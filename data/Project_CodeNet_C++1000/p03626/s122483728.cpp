#include<bits/stdc++.h>
using namespace std;

#define int long long




signed main(void){
    int MOD = 1e9+7;
    int n; cin >> n;
    vector<string>s(2);
    cin >> s[0] >> s[1];

    int ans = 3;
    int i;
    if(s[0][0]==s[1][0]){
        i=1;
    }else{
        i=2;
        ans*=2;
    }
    while(i<s[0].length()){
        if(s[0][i]==s[1][i]){
            if(s[0][i-1]==s[1][i-1]){
                ans = (ans*2);
            }
            i+=1;
        }else{
            if(s[0][i-1]==s[1][i-1]){
                ans = (ans*2);
            }else{
                ans = (ans*3);
            }
            i+=2;
        }
        ans = ans%MOD;
    }
    cout << ans << endl;
    return 0;
}