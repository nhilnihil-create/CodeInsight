/*
      author : nishi5451
      created: 12.08.2020 16:21:26
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string w;
    cin >> w;
    vector<int> dp(26);
    rep(i,int(w.size())){
        dp[w[i]-'a']++;
    }
    rep(i,26) if(dp[i]%2!=0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}