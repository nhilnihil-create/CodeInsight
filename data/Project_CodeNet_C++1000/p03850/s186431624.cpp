#include <iostream>
#include <vector>
using namespace std;
typedef long long lli;
lli n;
vector<lli> a;
lli dp[100005][3];
int main(int argc, char const *argv[]) {
    cin >> n;
    lli x;
    char c;
    cin >> x;
    a.push_back(x);
    for(lli i = 1;i < n;i++){
        cin >> c >> x;
        if(c == '-') a.push_back(x*-1);
        if(c == '+') a.push_back(x);
    }
    for(lli i = 0;i < a.size();i++){
        dp[i][0] = dp[i][1] = dp[i][2] = -100000000000000;
    }
    dp[0][0] = 0;
    for(lli i = 0;i < a.size();i++){
        if(a[i] > 0){
            dp[i+1][0] = max(dp[i][0]+a[i],dp[i][1]+a[i]);
            dp[i+1][1] = dp[i][1] - a[i];
            dp[i+1][2] = dp[i][2] + a[i];
        }else{
            dp[i+1][1] = dp[i][0]+a[i];
            dp[i+1][2] = max(dp[i][1]-a[i],dp[i][2]-a[i]);
        }
    }
    cout << max(max(dp[a.size()][0],dp[a.size()][1]),dp[a.size()][2]) << endl;
    return 0;
}
