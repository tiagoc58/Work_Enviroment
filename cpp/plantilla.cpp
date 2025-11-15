#include <bits/stdc++.h>
using namespace std;
#define Sonic ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tests(t) int t; cin >> t; while(t--)
#define F first
#define S second
#define pb push_back
#define ln cout<<endl;
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define read(x) for(auto &el : x) cin >> el;
#define reads(s, n) for(int i = 0, x; i < n; ++i) {cin >> x; s.insert(x);}
#define forn(i,n) for(int i=0; i < int(n); ++i)
#define forsn(i, s, n) for (int i = s; i < n; ++i)
#define dforn(i, n) for (int i = n - 1; i >= 0; --i)
#define DBG(x) cout << #x << " = " << x << endl;
#define print(x) for(auto &el : x) {cout << el << " ";} cout<<endl;
#define lw(c, x) int(lower_bound((c).begin(), (c).end(), (x)) - (c).begin())
#define up(c, x) int(upper_bound((c).begin(), (c).end(), (x)) - (c).begin())
#define sino(b) cout<<(b ? "YES\n":"NO\n");
#define syso(x) cout<< (x) <<endl;
#define vec(a) vector<a>
#define pr(a,b) pair<a,b>
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll;
ll gcd(ll a, ll b){while(b){a%=b; swap(a,b);} return a;} ll lcm(ll a,ll b){return a*b/gcd(a,b);}
int lg2(const int &x) { return 31-__builtin_clz(x);} // int lg2(const ll &x) {return 63-__builtin_clzll(x);}
// Para leer e imprimir .txt
// freopen("input.txt", "r", stdin);
// freopen("output.txt", "w", stdout);    

struct edge {
    int v;
    ll w;
};

struct edgePQ {
    int v; ll w;
    bool operator < (const edgePQ &o) const {
        return o.w < w; 
    }
};

struct edgeCmp {
  bool operator()(const edge& a, const edge& b) const {
    if (a.v == b.v) return false;  
    if (a.w != b.w) return a.w > b.w;         
    return a.v < b.v;            
  }
};

const int MX = 1e6+5;
const int oo = 1e9;
vi g[MX];
vi vis(MX), sccInd(MX), cmp(MX);
stack<int> pila;
int n, m, s, e, cnt, SCC;
//para el dag
vll dp(MX,0);
vector<set<edge, edgeCmp>> g2;
vector<bool> vis2;

void tarjan(int u){
  vis[u] = sccInd[u] = cnt++;
  pila.push(u);
  for(int &w : g[u]){
    if(vis[w] == -1) tarjan(w);
    sccInd[u] = min(sccInd[w], sccInd[u]);
  }
  if(sccInd[u] == vis[u]){
    while(pila.top()!=u){
      sccInd[pila.top()] = oo;
      cmp[pila.top()] = SCC;
      pila.pop();
    }
    sccInd[pila.top()] = oo;
    cmp[pila.top()] = SCC++;
    pila.pop();
  }
}

void init(){
  cnt = SCC = 0;
  for(int i = 0; i <= n; ++i){
    sccInd[i] = vis[i] = -1;
    g[i].clear();
  }
}

vector<ll> dist; // Almacena la distancia a cada nodo
void dijkstra(int u) {
  priority_queue<edgePQ> pq;
  pq.push({u, 0});
  dist[u] = 0;

  while (pq.size()) {
      u = pq.top().v; pq.pop();
      if (!vis2[u]) {
          vis2[u] = true;
          for (auto &ed : g2[u]) {
              int v = ed.v;
              if (!vis2[v] && dist[v] < dist[u] + ed.w) {
                  dist[v] = dist[u] + ed.w;
                  pq.push({v, dist[v]});
              }
          }
      }
  }
}

void solve(){
  cin >> n >> m >> s >> e; s--; e--;
  init();
  vi a(n); read(a)
  forn(i,m){
    int u,v; cin >> u >> v; u--; v--;
    g[u].pb(v);
  }
  forn(i,n) if(vis[i] == -1) tarjan(i);
  vll b(SCC);
  g2.assign(SCC, {});
  vis2.assign(SCC, false);
  dist.assign(SCC,0);
  forn(i,n) b[cmp[i]]+=a[i];
  forn(i,n){
    for(auto &v : g[i]) if(cmp[v] != cmp[i]) g2[cmp[i]].insert({cmp[v],b[cmp[i]]});
  }
  dijkstra(cmp[s]);
  syso(dist[cmp[e]]+b[cmp[e]])
}

int main(){
    Sonic
    // tests(t)
        solve();
    return 0;
}
//Chebitas + Sarita <3 (mis papis)