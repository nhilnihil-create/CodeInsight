#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    string s;
    cin>>s;
    int n=s.size();
    ll ans=0;
    for(int bit=0; bit<(1<<n-1); ++bit){
        ll sum=0;
        rep(i,n){
            sum+=s[i]-'0';
            if(bit&(1<<i)){
                ans+=sum;
                sum=0;
            }
            else{
                if(i==n-1)ans+=sum;
                else sum*=10;
            }
        }

    }
    cout<<ans<<endl;
}