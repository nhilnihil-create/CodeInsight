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
 P fi[1145140];
signed main(){
    int h,w,n;cin>>h>>w>>n;
    int d=0;
    rep(i,0,n){
        int a,b;cin>>a>>b;
        rep(i,0,3){
            rep(j,0,3){
                if(a>i&&b>j&&a-i<=h-2&&b-j<=w-2)fi[d].first=a-i,fi[d++].second=b-j;
            }
        }
    }
    sort(fi,fi+d);
    int ans[10]={};
    int key=1;
    rep(i,0,d-1){
        if(fi[i].first==fi[i+1].first&&fi[i].second==fi[i+1].second)key++;
        else if(i!=d-1){
            ans[key]++;
            key=1;
        }else key=1;
    }
    if(n)ans[key]++;
    int bans=0;
    rep(i,1,10){
        bans+=ans[i];
    }
    cout<<(h-2)*(w-2)-bans<<endl;
    rep(i,1,10)cout<<ans[i]<<endl;
    return 0;
}