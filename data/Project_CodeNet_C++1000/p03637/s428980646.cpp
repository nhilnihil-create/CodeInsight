#include <bits/stdc++.h>

#define rep(i, N) for (ll i = 0; i < N; i++)
#define rep1(i, N) for (ll i = 1; i <= N; i++)
#define repr(i, N) for (ll i = N-1; i >= 0; i--)
#define repr1(i, N) for (ll i = N; i > 0; i--)

#define MOD 1000000007

using ll = long long;
using namespace std;

typedef pair<int,int> P;
typedef vector<int> vi;
typedef vector<P> vpi;


int main() {
    ll N,num[4] = {0};
    cin >> N;
    int a;
    rep(i,N){
       cin >> a;
       a %= 4;
       num[a]++; 
    }
    
    if(num[0] >= num[1]+ (num[2]>0?1:0) + num[3] - 1) cout << "Yes";
    else cout << "No";    
    //cout << ans;
    //printf("%.15lf", ans);
    cout << "\n";
    return 0;
}
