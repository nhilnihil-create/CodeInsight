#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    int n; cin>>n;
    int sum=1,maxi=1;
    for(int i=2;i<=n;i++){
        if(sum<n&&n<=sum+i){
            sum+=i;
            maxi=i;
            break;
        }
        sum+=i;
    }
    rep(i,maxi){
        if(sum-n==i+1) continue;
        cout<<i+1<<endl;
    }
    return 0;
}
