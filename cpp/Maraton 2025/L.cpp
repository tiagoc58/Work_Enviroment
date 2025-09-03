#include <bits/stdc++.h>
using namespace std;
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tests(t) int t; cin >> t; while(t--)
#define F first 
#define S second
#define pb push_back
#define ln cout<<endl
#define sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define read(x) for(auto &el : x) cin >> el;
#define forn(i,n) for(int i=0; i < int(n); ++i)
#define forsn(i, s, n) for (int i = s; i < n; ++i)
#define dforn(i, n) for (int i = n - 1; i >= 0; --i)
#define DBG(x) cout << #x << " = " << x << endl;
#define print(x) for(auto &el : x) {cout << el << " ";} cout<<endl;
#define sino(b) cout<<(b ? "YES\n":"NO\n")
#define syso(x) cout<< x <<endl
#define vec(a) vector<a>
#define pr(a,b) pair<a,b>
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
typedef pair<ll,ll> pll; 

ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);} // lcm = (a*b/gcd(a,b))

const int MX = 1e5+5;
vector<int> g[MX];
vector<int> dist(MX);
vector<set<int>> cw(MX);

void bfs(int u) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;

    while (q.size()) {
        u = q.front();
        q.pop();
        for (auto &v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    
}



void solve() {
    int n, u, s, a, d, c; cin >> n >> u >> s >> a >> d >> c; //u sad? :c (yes i am)
    dist.assign(n+5,-1);
    for(int i = 0, u,v; i<c; ++i){
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
}

int main() {
    FastIO;
    //tests(tt) 
        solve();

    return 0;
}

// ᕦ(ò_ó)ᕤ