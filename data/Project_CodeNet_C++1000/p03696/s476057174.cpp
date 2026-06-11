#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    string ans;
    int k=0;
    string ss;
    rep(i,n){
        ss=s[i];
        if(ss=="("){
            ++k;
            ans=ans+"(";
        }
        else{
            if(k==0){
                ans="("+ans+")";
            }
            else{
                ans=ans+")";
                --k;
            }
        }
    }

    rep(i,k){
        ans=ans+")";
    }

    cout << ans << endl;
    

    return 0;
}