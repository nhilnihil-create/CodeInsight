/*
      author  : nishi5451
      created : 14.08.2020 13:11:10
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    vector<int> dp(26);
    rep(i,int(s.size())){
        dp[s[i]-'a']++;
    }
    rep(i,26){
        if(dp[i]>1){
            cout << "no" << endl;
            return 0;
        }
    }
    cout << "yes" << endl;
    return 0;
}