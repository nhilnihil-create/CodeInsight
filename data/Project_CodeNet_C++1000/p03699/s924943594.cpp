#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
using namespace std;
int main(){
    int n; cin>>n;
    vector<int>S(n);
    rep(i,n) cin>>S[i];
    sort(S.begin(), S.end());
    int sum = 0;
    int mini = 1000; //10の倍数でない最も小さい値を格納する用
    rep(i,n){
        sum += S[i];
        if (S[i]%10 != 0) mini = min(S[i], mini);
    }
  
    rep(i,n){
        if (sum%10 != 0){
            cout << sum << endl;
            return 0;
        }
    }
    sum -= mini;
    if (sum%10 != 0) cout << sum << endl;
    else cout << 0 << endl;
}