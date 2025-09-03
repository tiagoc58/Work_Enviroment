#include <bits/stdc++.h>
#define FastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
typedef long double ld;

int main(){
    FastIO;
    int t; cin>>t;
    while(t--){
        int n; cin >> n;
        map<int,int> di;
        for(int i = 2; i<=n; i++){
            if(i==n) di[i] = 2;
            else di[i] = i+1;
        }
        n--;
        int ini = 2;
        int i = ini;
        int j = i;
        while(n>1){
            j = di[i];
            if(__gcd(ini,j)>1 || j==ini){
                di[i] = di[j];
                ini = di[i];
                i = ini;
                n--;
                j = i;
            } else i = j;
        }
        cout << j << endl;
    }

}
