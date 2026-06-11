#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define fi first
#define se second
const int N = 3e5+6;
const int mod = 1e9+7;
const int inf = 1e8;
vector<int>divs[N];
int bit[N];
int mx[N];
int ans[N];
void add(int idx){
    for(int i=idx;i>0;i-=(i&-i))bit[i]++;
}
void del(int idx){
    for(int i=idx;i>0;i-=(i&-i))bit[i]--;
}
int sm(int idx){
    int ret = 0;
    for(int i=idx;i<N;i+=(i&-i))ret+=bit[i];
    return ret;
}
int inc[N];
void solve(){
    int n,m;
    cin>>n>>m;
    priority_queue<pair<int,int>> pq;
    for(int i=1;i<=n;i++){
        int l,r;
        cin>>l>>r;
        pq.push({-l,-i});
        pq.push({-r-1,i});
    }
    for(int i=1;i<=m;i++){
        for(int j=i;j<=m;j+=i){
            divs[j].pb(i);
        }
    }
    int mxm = 0;
    int cnt = 0;
    for(int i=1;i<=m;i++){
        while(!pq.empty()){
            int x = -pq.top().fi;
            if(x!=i)break;
            int y = pq.top().se;
    //        cout<<i<<" "<<x<<" "<<y<<endl;
            if(y<0){
                cnt++;
                inc[-y] = cnt;
                add(cnt);
                mxm = max(mxm,cnt);
            }
            else{
                del(inc[y]);
            }
            pq.pop();
        }

        for(int j:divs[i]){
      //      cout<<i<<" "<<j<<" "<<mx[j]<<" "<<sm(mx[j]+1)<<endl;
            ans[j]+=sm(mx[j]+1);
            mx[j] = max(mx[j],mxm);
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--)solve();
    return 0;
}
