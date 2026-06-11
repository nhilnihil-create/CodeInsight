#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define N 60
#define INF 1000000005
typedef long long ll;
#define ALL(v) (v).begin(),(v).end()
#define SZ(x) int(x.size())
#define IN(a) cin>>(a)
#define OUT(a) cout<<(a)<<endl
typedef pair<int,int> P;
const int MAX = 1000005;
const int MOD = 1000000007;
int main(){
    int n,L;
    cin>>n>>L;
    vector<int>a(n);
    REP(i,n)cin>>a[i];
    int tmp=-1;
    REP(i,n-1){
        if(a[i]+a[i+1]>=L){
            tmp=i;
            break;
        }
    }
    if(tmp==-1){
        OUT("Impossible");
    }else{
        OUT("Possible");
        REP(i,tmp)OUT(i+1);
        for(int i=n-2;i>tmp;i--)OUT(i+1);
        OUT(tmp+1);
    }
    return 0;
}