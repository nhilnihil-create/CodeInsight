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

vector<int> v[202020];
bool used[202020];
vector<int> ans;

void dfs(int x){
    used[x]=true;
    for(auto nx:v[x]){
        if(!used[nx]){
            ans.push_back(nx);
            dfs(nx);
            break;
        }
    }
}
int main(){
    int n,m;
    cin>>n>>m;
    rep(i,m){
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    dfs(1);
    reverse(ans.begin(),ans.end());
    ans.push_back(1);
    dfs(1);
    cout<<ans.size()<<endl;
    for(auto e:ans)cout<<e<<" ";
    return 0;
}