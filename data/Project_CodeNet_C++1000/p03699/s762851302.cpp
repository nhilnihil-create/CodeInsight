#include<bits/stdc++.h>
using namespace std;
using ll=long long int;
#define rep(i,n) for(int i=0;i<(n);i++)

int main(){
    int n;
    cin>>n;
    vector<int>s(n);
    rep(i,n) cin>>s[i];
    sort(s.begin(),s.end());
    int ans=0;
    rep(i,n){
        ans+=s[i];
    }
    if(ans%10!=0){
        cout<<ans<<endl;
        return 0;
    }
    int key=-1;
    rep(i,n){
        if(s[i]%10!=0){
            key=i;
            break;
        }
    }
    
    if(key==-1)ans=0;
    else ans-=s[key];
    cout<<ans<<endl;
    return 0;
}