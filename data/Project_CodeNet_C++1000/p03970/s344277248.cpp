#include <iostream>
#include <iomanip>
#include <string>
typedef long long ll;
using namespace std;
const  ll INF = 1e9;
const  ll MOD = 1e9 + 7;
#define repi(i,n,init) for(ll i=init;i<(n);i++)

int main()
{
    string aim = "CODEFESTIVAL2016",s;
    cin >> s;
    int ans = 0;
    repi(i,s.size(),0){
        if(s[i]!=aim[i])ans++;
    }
    cout << ans << endl;
    return 0;
}