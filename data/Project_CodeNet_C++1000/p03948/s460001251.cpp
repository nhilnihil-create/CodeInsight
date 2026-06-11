#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,t;
    cin>>n>>t;
    int a[n];
    rep(i,n)cin>>a[i];
    int ma=0;
    int tmp=0;
    int cnt=0;
    for(int i=n-1;i>=0;--i){
        ma=max(ma,a[i]);
        if(ma-a[i]>tmp){
            tmp=ma-a[i];
            cnt=1;
        }
        else if(ma-a[i]==tmp)++cnt;
    }
    cout<<cnt<<endl;
    return 0;
}