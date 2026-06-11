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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

vector<int> v[101010];
int dfs(int x,int p){
    int ret=0;
    for(auto to:v[x]){
        if(to==p)continue;
        ret^=dfs(to,x)+1;
    }
    return ret;
}

int main(){
    int n;
    cin>>n;
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        --a;--b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    cout<<(dfs(0,-1)?"Alice":"Bob")<<endl;
    return 0;
}