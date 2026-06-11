#include<bits/stdc++.h>
#define vi vector<int>
#define vvi vector<vector<int> >
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vc vector<char>
#define vs vector<string>
using ll = long long;
using ld =long double;
#define int ll
#define INF 1e9
#define EPS 0.0000000001
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,s,n) for(int i=s;i<n;i++)
#define all(in) in.begin(), in.end()
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
#define MAX 9999999
using namespace std;
typedef pair<int, int> pii;
typedef pair<int,pii> piii;
#define mp make_pair
int h,w;
map<pii,int>Mp;
map<pii,int>res;
void solve(){
    int mv[]={0,1,2};
    for(auto itr:Mp){
        pii temp=itr.first;
        if(itr.second==0)continue;
        rep(j,3)rep(k,3){
            int x=temp.second-mv[j];
            int y=temp.first-mv[k];
            if((1<=x&&x+2<=w)&&(1<=y&&y+2<=h)){
                res[mp(y,x)]++;
            }
        }
    }
}
signed main(){
    cin>>h>>w;
    int n; cin>>n;
    rep(i,n){
        pii temp;cin>>temp.first>>temp.second;
        Mp[temp]++;
    }
    solve();
    vector<int>ans(10,0);
    ans[0]=(h-2)*(w-2)-res.size();
    for(auto itr:res)ans[itr.second]++;
    for(int i=0;i<=9;i++)cout<<ans[i]<<endl;
}
