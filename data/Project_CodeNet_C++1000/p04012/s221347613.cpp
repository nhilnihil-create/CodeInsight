#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int main(void){
    string S;
    cin >> S;
    string ans = "Yes";
    int dp[1000] = {0};
    for(int i=0;i<S.size();i++){
        dp[S[i]]++;
    }
    for(int i='a';i<='z';i++){
        if(dp[i] % 2 == 1){
            ans = "No";
        }
    }
    cout << ans << endl;
}
