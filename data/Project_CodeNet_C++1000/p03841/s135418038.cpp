#include "bits/stdc++.h"
#define ll long long
#define rep2(i,a,b) for(int i=a;i<=b;++i)
#define rep(i,n) for(int i=0;i<n;i++)
#define pii pair<int,int>
#define tii tuple<int,int,int>
#define pq priority_queue<int>
#define pqg priority_queue<int,vector<int>,greater<int>>
#define pb push_back
ll int MOD=998244353;
#define INF 2*1e9
#define N 310000
 
using namespace std;
string alphabet("abcdefghijklmnopqrstuvwxyz");

main(){
    int n;
    cin>>n;
    int a[600],ans[N]={};
    vector<pii> p;
    rep2(i,1,n){
        cin>>a[i];
        if(ans[a[i]]){
            cout<<"No"; return 0;
        }
        ans[a[i]]=i;
        p.pb({a[i],i});
    }
    sort(p.begin(),p.end());
    int res[600]={};
    rep2(i,1,n){
        res[i]=i-1;
    }
    int pos=0;
    rep2(i,1,n*n){
        if(ans[i]&&res[ans[i]]){
            cout<<"No";return 0;
        }
        else if(ans[i]) continue;
        if(pos>n-1) continue;
        else{
            if(res[p[pos].second]){
                res[p[pos].second]--;
                ans[i]=p[pos].second;
            }
            else{
                pos++;
                if(!res[p[pos].second]){
                    pos++;
                }
                res[p[pos].second]--;
                ans[i]=p[pos].second;
            }
        }
    }
    rep2(i,1,n){
        res[i]=n-i;
    }
    rep2(i,1,n){
        ans[a[i]]=-i;
    }
    queue<int> q;
    rep2(i,1,n*n){
        if(ans[i]<0){
            q.push(-ans[i]);ans[i]*=-1;continue;
        }
        if(!ans[i]&&q.empty()){
            cout<<"No";return 0;
        }
        if(!ans[i]){
            if(res[q.front()]){
                ans[i]=q.front();res[q.front()]--;
            }
            else{
                q.pop();
                if(q.empty()){
                    cout<<"No";return 0;
                }
                if(!res[q.front()]){
                    q.pop();
                    if(q.empty()){
                        cout<<"No";return 0;
                    }
                }
                ans[i]=q.front();res[q.front()]--;
            }
        }
    }
    cout<<"Yes"<<endl;
    rep2(i,1,n*n){
        cout<<ans[i]<<" ";
    }
}
