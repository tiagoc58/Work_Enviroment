#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;

int main(){

    FastIO;
    ll t; cin>>t;
    ll inv = 166666668ll;
    for(int i = 0; i < t; i++) {
        ll k;
        cin >> k;
        cout << (((k % MOD) * ((k - 1 + MOD) % MOD) % MOD) * ((k - 2 + MOD) % MOD) % MOD * inv) % MOD << '\n';
    }

}
