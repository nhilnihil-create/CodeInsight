#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007;
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

vector<vector<int> > v(2000);
int ans=mod,num=0,k;
void dfs(int now,int count,int p){
	if(count>k)num++;
	for(auto& i:v[now]){
		if(p==i)continue;
		dfs(i,count+1,now);
	}
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>k;
    vector<pair<int,int> > ve;
    for(int i=1;i<n;i++){
    	cin>>a>>b;
    	a--,b--;
    	v[a].pb(b);
    	v[b].pb(a);
    	ve.push_back({a,b});
    }
    if(k&1){
    	k/=2;
    	for(auto& i:ve){
    		num=0;
    		dfs(i.first,0,i.second);
    		dfs(i.second,0,i.first);
    		ans=min(ans,num);
    	}
    }
    else{
    	k/=2;
    	for(int i=0;i<n;i++){
    		num=0;
    		dfs(i,0,-1);
    		ans=min(ans,num);
    	}
    }
    cout << ans<<endl;
    return 0;
}
