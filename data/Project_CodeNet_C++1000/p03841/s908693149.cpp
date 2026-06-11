//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n; cin>>n;
    vector<pp> x(n);
    vector<int> c(n,0),ans(n*n,0);
    rep(i,n){
        c[i]=i;
        int a; cin>>a;
        x[i]=mk(a,i);
    }
    sort(al(x));
    int idx=0,cur=0;
    queue<int> que;
    rep(i,n*n){
        if(cur<n && x[cur].first-1==i){
            if(c[x[cur].second]>0){
                cout<<"No"<<endl;
                return 0;
            }
            ans[i]=x[cur].second+1;
            rep(j,n-(x[cur].second+1)) que.push(x[cur].second+1);
            cur++;
        }
        else{
            while(idx<n && c[x[idx].second]==0) idx++;
            if(idx==n){
                if(que.size()==0){
                    cout<<"No"<<endl;
                    return 0;
                }
                ans[i]=que.front();
                que.pop();
            }
            else{
                ans[i]=x[idx].second+1;
                c[x[idx].second]--;
            }
        }
    }
    cout<<"Yes"<<endl;
    rep(i,n*n) cout<<ans[i]<<" ";
    cout<<endl;
}
