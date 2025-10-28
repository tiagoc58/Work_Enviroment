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
#define sino(b) cout<<(b ? "yes\n":"no\n");
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
/*
    Para leer e imprimir .txt
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);    
*/

const ll inf = -1e18;
const int MX = 2505; // Cantidad maxima de nodos
vector<pii> g[MX]; // Lista de adyacencia, u->[(v, cost)]
vector<ll> dist; // Almacena la distancia a cada nodo
vector<bool> vis;
// vector<int> cycle; // Para construir el ciclo negativo
int n, m; // Cantidad de nodos y aristas

// O(n*m)
void bellmanFord(int src) {
    vis.assign(n, false);
    dist.assign(n, inf);
    dist[src] = 0;
    for (int i = 0; i < n-1; i++) 
        for (int u = 0; u < n; u++) 
            if (dist[u] != inf) 
                for (auto &v : g[u]) {
                    dist[v.F] = max(dist[v.F], dist[u] + v.S);
                }
    // Encontrar ciclos negativos
    // cycle.clear();
    for (int u = 0; u < n; u++) 
        if (dist[u] != inf) 
            for (auto &v : g[u]) 
                if (dist[v.F] < dist[u] + v.S) { // Ciclo negativo
                    dist[v.F] =  -inf;
                    // cycle.pb(v.F); // Para reconstruir
                }
}

void dfs(int u){
    vis[u] = true;
    for(auto &[v,w] : g[u]){
        if(!vis[v]){
            dist[v] = -inf;
            dfs(v);
        }
    }
}

void init() {
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

void solve(){
    cin >> n >> m;
    init();
    for(int i = 0,u,v,x; i < m; ++i){
        cin >> u >> v >> x;
        u--;    v--;
        g[u].pb({v,x});
    }
    bellmanFord(0);
    for(int i = 0; i < n; ++i) if(dist[i] == -inf && !vis[i]) dfs(i);
    if(dist[n-1] == inf) syso(0)
    else if(dist[n-1] == -inf) syso(-1)
    else syso(dist[n-1])
}

int main(){
    Sonic
    // tests(t)
        solve();
    return 0;
}