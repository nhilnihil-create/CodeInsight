#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    long long n; cin>>n;
    long long sum=0;
    long long a[n]; rep(i,n) {cin>>a[i];sum+=a[i];}
    if(sum/(n*(n+1)/2)*(n*(n+1)/2)!=sum){
        cout<<"NO"<<endl;
        return 0;
    }
    sum/=(n*(n+1)/2);
    long long sabun[n];
    rep(i,n){
        sabun[i]=a[i+1]-a[i];
    }
    sabun[n-1]=a[0]-a[n-1];
    long long cnt=0;
    rep(i,n){
        sabun[i]-=sum;
        if(sabun[i]%n==0&&sabun[i]<0){
            cnt-=sabun[i]/n;
        }
    }
    if(sum==cnt) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
