#include <bits/stdc++.h>
using namespace std;
#define Sonic ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tests(t) int t; cin >> t; while(t--)
#define pb push_back
#define syso(b) cout << (b) << endl;
typedef long long ll;
typedef long double ld;

const ld pi = acos(-1);
const int MX = 105;
ld dp[MX][MX][MX];
vector<ld> x(MX), y(MX);
int n,p;

//sum no entra en la misma memoizacion ya que no se alcanza a llegar a un estado donde se repita f(i,j,m) pero con diferente suma
ld f(int i, int j, int m, ld sum){
    if(m == p) return fabsl(sum + x[j]*y[i] - x[i]*y[j])/2.0;
    ld &ans = dp[i][j][m];
    if(ans != -1) return ans;
    ans = (m >= 3 ? fabsl(sum + x[j]*y[i] - x[i]*y[j])/2.0 : 0);  //como se pueden usar menos de p puntos, veo si ya puedo cerrar el poligono
    for(int k = j+1; k < n; k++){
        ans = max(ans, f(i, k, m + 1, sum + x[j]*y[k] - x[k]*y[j]));
    }
    return ans;
}

void init(){
    for(int i = 0; i <= n; ++i) for(int j = 0; j <= n; ++j) for(int k = 0; k <= n; ++k){
        dp[i][j][k] = -1;
    }
}
 
void solve(){
    cin >> n >> p;
    init();
    for(int i = 0; i < n; ++i){
        ld c; cin >> c;
        x[i] = 1000*cos(pi*c/180);
        y[i] = 1000*sin(pi*c/180);
    }
    x[n] = x[0];
    y[n] = y[0];
    ld ans = 0;
    for(int i = 0; n - i >= p; ++i) ans = max(ans,f(i,i,1,0));
    cout << fixed << setprecision(11) << ans << endl;
}

int main(){
    Sonic;
    //tests(t)
        solve();
}

//ñ power