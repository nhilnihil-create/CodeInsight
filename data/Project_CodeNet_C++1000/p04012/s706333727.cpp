#include <bits/stdc++.h>
using namespace std;
int main(){
    string w;
    cin >> w;
    vector <int>dp(26,0);
    for(int i = 0; i < w.length(); i++){
        dp[w[i]-'a']++;
    }
    for(int i = 0; i < dp.size(); i++){
        if(dp[i]%2==1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}