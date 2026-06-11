#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll=long long;
using vi=vector<int>;
using vll=vector<ll>;
#define MOD 1000000007

int main(){
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;

    bool state;
    int a;
    ll ans=1;
    if(s[0]==t[0]){
        ans*=3;
        state=true;
        a=1;
    }else{
        ans*=6;
        state=false;
        a=2;
    }
    for(int i=a;i<s.size();i++){
        if(s[i]==t[i]){
            if(state){
                ans*=2;
            }else{
                ans*=1;
            }
            state=true;
        }else{
            if(state){
                ans*=2;
            }else{
                ans*=3;
            }
            state=false;
            i++;
        }
    }
    cout << ans%MOD << endl;
}