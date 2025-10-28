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

void solve(){
    ll n,k;
    while(cin >> n >> k){
        vector<ll> v(k);
        for(ll i = 0; i < k; ++i) cin >> v[i];
        if(k==n) cout << 0 << endl;
        else if(k == 1) cout << v[0] << endl;
        else {
            vector<vector<ll>> g(k, vector<ll>(n-k+1,0));
            for(ll i = 0; i < n-k+1; ++i) g[0][i] = 1;
            for(ll i = 1; i < k; ++i){
                for(ll j = 0; j < n-k+1; ++j){
                    for(ll z = j; z < n-k+1; ++z){
                        g[i][j] += g[i-1][z];
                    }
                }
            }
            ll ans = 0, last = 0;
            for(ll i = k-1; i >= 0; i--){
                for(ll j = 0; j < v[k-1-i]-k+i; ++j){
                    if(k-i+j > last) ans += g[i][j];
                }
                last = v[k-1-i];
            }
            cout << ans << endl;
        }
    }
}

int main(){
    Sonic
    // tests(t)
        solve();
    return 0;
}

//¿Si chebitas?