#include <bits/stdc++.h>
using namespace std;
#define Sonic ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
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
#define lw(c, x) int(lower_bound((c).begin(), (c).end(), (x)) - (c).begin())
#define up(c, x) int(upper_bound((c).begin(), (c).end(), (x)) - (c).begin())
#define sino(b) cout<<(b ? "YES\n":"NO\n")
#define syso(x) cout<< x <<endl;
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

void solve(){
    int n, x; cin >> n >> x;
    int lf = 0, rg = n+1;
    vec(char) v(n); read(v)
    x--;
    for(int i = x-1; i >= 0 && lf == 0; --i) if(v[i] == '#') lf = i+1;
    for(int i = x+1; i < n && rg == 0; ++i) if(v[i] == '#') rg = i+1;
    x++;
    if(x == 1 || x == n || (lf==0 && rg==n+1)) {syso(1) return;} //(lf==0 && rg==0)
    if(lf > n-rg+1) rg = x+1;
    else lf = x-1;
    syso(min(lf+1,n-rg+2));
}

int main(){
    Sonic
    tests(t)
        solve();
    return 0;
}