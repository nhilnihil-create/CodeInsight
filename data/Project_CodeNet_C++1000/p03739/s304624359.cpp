#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<ll,ll> P;
typedef vector<ll> vec;
typedef vector<vec> mat;
ll mod=1e9+7;
int main(){
    ll n,a[200001],b[200001];
    cin>>n;
    rep(i,n) cin>>a[i],b[i]=a[i];
    ll sum=0,ans1=0,ans2=0;
    rep(i,n){
        if(i%2==0){
            sum+=a[i];
            if(sum<=0) ans1+=(-1)*sum+1,a[i]+=(-1)*sum+1,sum=1;
        }
        if(i%2){
            sum+=a[i];
            if(sum>=0) ans1+=sum+1,a[i]-=sum+1,sum=-1;
        }
        //cout<<a[i]<<"\n";
    }
    sum=0;
    rep(i,n){
        if(i%2==1){
            sum+=b[i];
            if(sum<=0) ans2+=(-1)*sum+1,b[i]+=(-1)*sum+1,sum=1;
        }
        if(i%2==0){
            sum+=b[i];
            if(sum>=0) ans2+=sum+1,b[i]-=sum+1,sum=-1;
        }
        //cout<<a[i]<<"\n";
    }
    cout<<min(ans1,ans2)<<"\n";
}