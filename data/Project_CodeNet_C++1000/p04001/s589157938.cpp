#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
typedef pair<int,int> P;
const int INF=1e9;
int main(){
    string s;
    cin>>s;
    ll ans=0;
    int n=s.size();
    rep(i,1<<(n-1)){
        ll allsum=0,sum=s[0]-'0';
        for(int j=1;j<n;j++){
            if(i>>(j-1)&1){
                sum=sum*10+s[j]-'0';
            }
            else{
                allsum+=sum;
                sum=0;
                sum=s[j]-'0';
            }
        }
        ans+=allsum+sum;
    }
    cout<<ans;
}