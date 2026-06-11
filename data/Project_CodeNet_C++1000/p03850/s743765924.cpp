#include <iostream>
#include <vector>
using namespace std;
typedef long long lli;
lli n;
vector<lli> a;
lli dp[100005][2][2];
int main(int argc, char const *argv[]) {
    cin >> n;
    lli x;
    char c;
    cin >> x;
    a.push_back(x);
    for(lli i = 1;i < n;i++){
        cin >> c >> x;
        if(c == '-') a.push_back(x*-1);
        if(c == '+'){
            if(a.back() > 0) a.back() += x;
            else a.push_back(x);
        }
    }
    for(lli i = 0;i < a.size();i++){
        dp[i][0][0] = dp[i][1][0] = dp[i][1][1] = -100000000000000;
    }
    if(a.size() == 1){
        cout << a[0] << endl;
        return 0;
    }
    dp[2][0][0] = dp[2][1][1] = a[0]+a[1];
    for(lli i = 2;i < a.size();i++){
        if(a[i] < 0){
            dp[i+1][0][0] = dp[i][0][0]+a[i];
            dp[i+1][1][0] = max(dp[i][1][0]+a[i],dp[i][1][1]-a[i]);
            dp[i+1][1][1] = max(dp[i][1][0]+a[i],max(dp[i][1][1]-a[i],dp[i][0][0]+a[i]));
        }else{
            dp[i+1][0][0] = dp[i][0][0]+a[i];
            dp[i+1][1][0] = max(dp[i][1][0]+a[i],dp[i][1][1]-a[i]);
            dp[i+1][1][1] = max(dp[i][1][0]+a[i],dp[i][1][1]-a[i]);
        }
    }
    cout << max(max(dp[a.size()][0][0],dp[a.size()][1][0]),dp[a.size()][1][1]) << endl;
    return 0;
}
