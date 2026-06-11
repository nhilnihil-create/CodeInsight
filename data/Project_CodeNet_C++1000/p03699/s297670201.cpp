#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;

int main(){
    cin>>n;
    vector<int> s(n);
    int sum=0;
    rep(i,0,n){
        cin>>s[i];
        sum+=s[i];
    }
    int ans=0;
    if(sum%10!=0) ans=sum;
    else{
        sort(s.begin(),s.end());
        rep(i,0,n){
            if(s[i]%10!=0){
                ans=sum-s[i];
                break;
            }
        }
    }
    cout<<ans<<"\n";
}