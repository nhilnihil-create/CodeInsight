#include <iostream>
#include <vector>
using namespace std;
#define int long long
vector<int> dp,dpf;
signed main(){
    int n, m, a, prev, ans = 0, maxs = 0;
    cin >> n >> m >> prev;
    dp.resize(m+2);dpf.resize(m+2);
    for(int i = 1; i < n; i++){
        cin >> a;
        ans += (a+m-prev)%m;
        if(a == prev)continue;
        if(a < prev){
            dp[0]+=m-prev-1;
            dpf[0]++;
        }
		dp[a] -= (a-prev+m-1)%m;
        dpf[prev+1]++;
        dpf[a]--;
        prev = a;
    }
    for(int i = 0; i <= m; i++){
        if(i!=m)dpf[i+1] += dpf[i];
        dpf[i] += dp[i];
        if(i)dpf[i] += dpf[i-1];
        maxs = max(maxs, dpf[i]);
    }
    cout << ans-maxs << endl;

}
