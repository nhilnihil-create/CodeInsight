#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll l;
    l=s.size();
    ll la;

    string s2,ans;
    rep(i,l){
        if(i==l-1){
            la=k%26;
            if((int(s[i])+la)<=122){
                s[i]=s[i]+la;
                ans=ans+s[i];
            }
            else{
                s[i]=s[i]-26+la;
                ans=ans+s[i];
            }
        }
        else{
        if(int(s[i])==97){
            ans=ans+s[i];
        }
        else{
            if((123-int(s[i]))<=k){
                ans=ans+'a';
                k-=123-int(s[i]);
            }
            else{
                ans=ans+s[i];
            }
        }
        }
        
    }

    cout << ans << endl;

    

    return 0;
}