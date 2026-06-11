#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    long long a[7]; rep(i,7) cin>>a[i];
    long long ans1=0,ans2=0;
    ans1+=a[0]/2*2;
    ans1+=a[1];
    ans1+=a[3]/2*2;
    ans1+=a[4]/2*2;
    if(a[0]>0&&a[3]>0&&a[4]>0){
        ans2+=3;
        a[0]--;
        a[3]--;
        a[4]--;
    }
    ans2+=a[0]/2*2;
    ans2+=a[1];
    ans2+=a[3]/2*2;
    ans2+=a[4]/2*2;
    cout<<max(ans1,ans2)<<endl;
    return 0;
}
