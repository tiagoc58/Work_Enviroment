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

const int MX = 1e6+5;
const int oo = 1e9;
vi g[MX];
vi vis(MX), sccInd(MX), cmp(MX);
stack<int> pila;
//para el dag
vector<set<int>> g2;
vector<bool> vis2;
int n, m, cnt, SCC, ans;

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

void dfs(int u){
  vis2[u] = true;
  ans += !sz(g2[u]);
  for(const int &v : g2[u]) if(!vis2[v]) dfs(v);
}

void init(){
  cnt = SCC = 0;
  for(int i = 0; i <= n; ++i){
    sccInd[i] = vis[i] = -1;
    g[i].clear();
  }
}

void solve(){
  cin >> n >> m;
  init();
  for(int i = 0,u,v; i < m; i++){
    
  }
}

int main(){
    Sonic
    // tests(t)
        solve();
    return 0;
}