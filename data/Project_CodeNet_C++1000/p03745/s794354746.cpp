#include<bits/stdc++.h>
#define rep(i,j,n) for(int i=(j);i<(n);i++)
#define per(i,n,j) for(int i=(n)-1;i>=(j);i--)
using ll=long long;
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF=1LL<<60;

int n;
vector<int> a(100100);


int main(){
    cin>>n;
    rep(i,0,n) cin>>a[i];

    int cnt=0;
    int flag;
    if(a[0]==a[1]) flag=0;
    else if(a[0]>a[1]) flag=1;
    else if(a[0]<a[1]) flag=2;

    int ans=1;
    rep(i,1,n-1){
        if(flag==0){
            if(a[i]>a[i+1]) flag=1;
            else if(a[i]<a[i+1]) flag=2;
        }
        else if(flag==1){
            if(a[i]<a[i+1]){
                ans++;
                flag=0;
            }
        }
        else if(flag==2){
            if(a[i]>a[i+1]){
                ans++;
                flag=0;
            }
        }
    }
    cout<<ans<<"\n";
    return 0;
}
