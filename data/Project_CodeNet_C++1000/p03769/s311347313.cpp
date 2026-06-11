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

deque<int> ans1,ans2;

void solve(ll n,int& x){
    if(n==0)return ;
    if(n==1){
        ans1.push_front(x);ans2.push_front(x);
        ++x;
        return;
    }
    solve((n-1)/2,x);
    ans1.push_front(x);ans2.push_front(x);
    ++x;
    if(n%2==0){
        ans1.push_front(x);ans2.push_back(x);
        ++x;
    }
}
int main(){
    ll n;
    cin>>n;
    int x = 1;
    solve(n,x);
    cout<<ans1.size()+ans2.size()<<endl;
    for(auto e : ans1)cout<<e<<" ";
    for(auto e : ans2)cout<<e<<" ";
    return 0;
}