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

const ld pi = acos(-1);
const ld dif = 1e-6;

void solve() {
    ld r, R, h;
    cin >> r >> R >> h;
    ld teta = atan((R-r)/h);
    ld vol = (pi*h*(r*r+R*R+r*R))/3;
    ld lo = h/2, hi = h, mH, nR, nV;
    while(lo<=hi){
        mH = (lo+hi)/2;
        nR = tan(teta)*mH + r;
        nV = (pi*mH*(r*r+nR*nR+r*nR))/3;
        if(nV-(vol/2)>dif) hi = mH-dif;
        else lo = mH+dif;
    }
    cout << fixed << setprecision(9) << lo << endl;    
}

int main() {
    FastIO;
    tests(tt) 
        solve();

    return 0;
}

// ᕦ(ò_ó)ᕤ