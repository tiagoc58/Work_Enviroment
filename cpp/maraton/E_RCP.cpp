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

// lcm = (a*b/gcd(a,b))
ll gcd(ll a, ll b) {while (b) {a %= b;swap(a, b);}return a;} 

string s; 
const ll oo = 1e18;

bool valid(){
    if (s[sz(s)-1] != 'O') return false;
    for (int i = 0; i < sz(s); ++i) {
        if (s[i] != 'E' && s[i] != 'O') return false;
        if (i > 0 && s[i] == 'O' && s[i-1] == 'O') return false;
    }
    return true;
}

ll solomillos(ll n){
    for(int i = sz(s)-1; i>=0; --i){
        if(s[i]=='O') {
            if((n-1)%3ll!=0) return oo;
            n = (n-1)/3;
        }
        else n<<=1;
        if(!(n == 0) && !(n & (n - 1))) return oo;
    }
    return n;
}

void solve() {
    cin >> s;
    if(!valid()) {syso("INVALID"); return;}
    ll x = oo;
    for(ll i = 4; i<=(1ll<<47); i <<= 1){
        x = min(x,solomillos(i));
        if(x!=oo) {syso(x); return;}
    }
    syso("INVALID");
}

int main() {
    FastIO;
    //tests(tt) 
        solve();
 
    return 0;
}

// ᕦ(ò_ó)ᕤ