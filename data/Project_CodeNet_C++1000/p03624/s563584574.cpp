/*
      author  : nishi5451
      created : 14.08.2020 14:47:11
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    vector<bool> dp(26,false);
    rep(i,int(s.size())){
        dp[s[i]-'a']=true;
    }
    rep(i,26){
        if(dp[i]==false){
            cout << char('a'+i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;

    return 0;
}