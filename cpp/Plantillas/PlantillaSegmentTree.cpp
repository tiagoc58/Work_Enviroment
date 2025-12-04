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
int lg2(const int &x) { return 31-__builtin_clz(x);}

typedef int T; // tipo de dato del segtree
struct segtree {
    vector<T> st; // , lazy;
    int n; T neutro = 1e9; // "infinito"

    segtree(const vector<int> &v) {
        n = v.size();
        st.assign(n*4, 0);
        // lazy.assign(n*4, neutro);
        build(1, 0, n-1, v);
    }

    void build(int p, int L, int R, const vector<int> &v) {
        if (L == R) st[p] = v[L];
        else {
            int m = (L+R)/2, l = p*2, r = l+1;
            build(l, L, m, v);
            build(r, m+1, R, v);
            st[p] = min(st[l], st[r]);
        }
    }
    /*
    void propagate(int p, int L, int R, T val) {
        if (val == neutro) return;
        st[p] = val;
        lazy[p] = neutro;
        if (L == R) return;
        int l = p*2, r = l+1;
        lazy[l] = lazy[r] = val;
    }
    */
    T query(int i, int j) { return query(1, 0, n-1, i, j); }
    void upd(int i, int j, T val) { upd(1, 0, n-1, i, j, val); }

    T query(int p, int L, int R, int i, int j) {
        // propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return neutro;
        if (i <= L && j >= R) return st[p];
        int m = (L+R)/2, l = p*2, r = l+1;
        T lf = query(l, L, m, i, j);
        T rg = query(r, m+1, R, i, j);
        return min(lf, rg);
    }

    void upd(int p, int L, int R, int i, int j, T val) {
        // propagate(p, L, R, lazy[p]);
        if (i > R || j < L) return;
        if (i <= L && j >= R) st[p] = val; // cambiar por propagate(p, L, R, val);
        else {
            int m = (L+R)/2, l = p*2, r = l+1;
            upd(l, L, m, i, j, val);
            upd(r, m+1, R, i, j, val);
            st[p] = min(st[l], st[r]);
        }
    }
};

void solve() {
    int n; cin >> n;
    vi a(n); read(a);
    segtree s(a);
    int q; cin >> q;
    forn(i,q){
        int l,r; cin >> l >> r; l--; r--;
        cout << s.query(l,r) << endl;
    }
}
   

int main() {
    Sonic;
    //tests(tt) 
        solve();
 
    return 0;
}
 
// ᕦ(ò_ó)ᕤ