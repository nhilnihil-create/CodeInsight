#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define size_of_array(array) (sizeof(array)/sizeof(array[0]))
#define max 100005
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;

int main(){

    string s;
    cin>>s;
    ll ans=0;
    rep(i,pow(2,s.size()-1)){
        ll k=1;
        int j;
        for(j=0;j<s.size()-1;j++){
            if((i>>j)&1){
                ans+=(s[s.size()-1-j]-'0')*k;
                k=1;
            }else{
                ans+=(s[s.size()-1-j]-'0')*k;
                k*=10;
            }
        }
        ans+=(s[s.size()-1-j]-'0')*k;
    }
    cout<<ans<<endl;
    return 0;
}