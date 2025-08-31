#include <bits/stdc++.h>
using namespace std;
#define Sonic ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tests(t) int t; cin >> t; while(t--)
#define pb push_back
#define syso(b) cout << (b) << endl;
typedef long long ll;
typedef long double ld;

const int MX = 1e6+5;
vector<ll> dp(MX, -1);
vector<int> a(MX);
int n;

ll f(int i){
    if(i >= n-1) return 0;
    ll &ans = dp[i], dist = 0;
    if(ans != -1ll) {return ans;}
    ans = 1e18;
    int last = 1;
    for(int j = i+1; j < n; ++j, ++dist){
        if(a[j] < a[i]) continue;
        if(dist*dist > ans) break;
        last = 0;
        ans = min(ans, dist*dist + f(j));
    }
    return ans = ans*(1-last) + (n-i-1)*(n-i-1)*last;
}

void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];  
    ll ans = 1e18;
    for(int i = 0; i < n; ++i) ans = min(ans, f(i) + i*i);
    cout << ans << endl;
}

int main(){
    Sonic
    // tests(t)
        solve();
}

//ñ power