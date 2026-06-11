#include <iostream>
#include<algorithm>
#include<set>
#include<queue>
#include<bitset>
#define rep(i,j,n) for(int i=j;i<n;i++)
using namespace std;
#define int long long
struct edge{long long to,cost;};
typedef pair<int,int>P;
#define inf 1000000007
string alph("abcdefghijklmnopqrstuvwxyz");
vector<int> es[114514];
signed main(){
    int n,t;cin>>n>>t;
    int pri[114514];
    rep(i,0,n)cin>>pri[i];
    int mini=pri[0];
    int d[114514];
    int j=0;
    rep(i,1,n){
        if(pri[i]<mini){
            mini=pri[i];
        }else {
            d[j++]=pri[i]-mini;
        }
    }
    sort(d,d+j);
    reverse(d,d+j);
    int ans=1;
    rep(i,1,j){
        if(d[i]==d[i-1])ans++;
        else break;
    }
    cout<<ans<<endl;
    return 0;
}
