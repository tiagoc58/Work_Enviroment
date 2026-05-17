#include <bits/stdc++.h>
using namespace std;
#define Sonic ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tests(t) int t; cin >> t; while(t--)
#define F first
#define S second
#define pb push_back
#define eb emplace_back
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

//metodo para multiplicar un string por un valor x, este siempre será menor que 10
string mul(string &b, int x){
    string tmp = "";
    int exc = 0;
    for(int i = sz(b)-1; i >= 0; --i){
        int d = b[i]-'0', mul = d*x + exc;
        tmp += to_string(mul%10);
        exc = mul/10; 
    }
    if(exc) tmp += to_string(exc);
    reverse(all(tmp));
    return tmp;
}

//metodo para restar strings
string res(string a, string b){
    int j = sz(a)-1;
    bool lleva = 0;
    for(int i = sz(b)-1; i >= 0; --i){
        int x = a[j]-'0', y = b[i]-'0';
        if(lleva) x--, lleva = 0;
        if(x < y) x+=10, lleva = 1;
        x-=y;
        a[j] = x + '0';
        j--;
    }
    if(lleva) a[j]--;
    return a;
}

//metodo para saber si string b es mayor que string a lexicograficamente
int cmp_sz(string a, string &b){
    int i = 0, j = 0;
    while(a[i] != 0 && ) i++;
    for(int i = 0; i < sz(a); ++i) if(a[i] != b[i]) return a[i] > b[i] ? -1 : 1;
    return 0;
}

void solve(){
    string dvn, dvs; cin >> dvn >> dvs;
    if(sz(dvs) > sz(dvn)) syso("NO");
    string tmp = "";
    for(int i = 0; i < sz(dvn); ++i){
        if(sz(tmp) < sz(dvs) || (sz(tmp) == sz(dvs) && cmp_sz(tmp,dvs) == 1)) tmp += to_string(dvn[i]);
        else{
            int x = 2;
            while(cmp_sz(mul(dvs,x), tmp) != -1) x++;
            tmp = res(tmp,mul(dvs,x-1));
        }
    }
}

int main(){
    Sonic  
    // tests(t)
        solve();
    return 0;
}
//"Quiero picha" - Sebastian Nieto 2026