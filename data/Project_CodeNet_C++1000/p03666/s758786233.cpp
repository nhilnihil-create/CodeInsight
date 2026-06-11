#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
using namespace std;
const int INF=1145141919,MOD=1e9+7;
const long long LINF=8931145141919364364,LMOD=998244353;
inline long long mod(long long n,long long m){return(n%m+m)%m;}
// const int dx[]={1,0,-1,0,1,1,-1,-1},dy[]={0,-1,0,1,1,-1,-1,1};

int main(){
    long long n,a,b,c,d; cin>>n>>a>>b>>c>>d;
    string ans="NO";
    for(long long m=0;m<n;m++){
        if(c*(n-1-m)-d*m<= b-a && b-a <= -c*m+d*(n-1-m)){
            ans="YES";
        }
    }
    cout<<ans<<endl;
    return 0;
}
