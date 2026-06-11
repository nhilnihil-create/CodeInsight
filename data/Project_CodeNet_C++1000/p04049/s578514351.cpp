#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long int ll;

int n,k;
vector<int> G[2100];

int dfs(int to,int from,int k,int depth=0){
	int cnt=0;
	if(depth>=k)cnt++;
	for(auto d:G[to]){
		if(d==from)continue;
		cnt+=dfs(d,to,k,depth+1);
	}
	return cnt;
}

int main(){
	cin >> n >> k;
	for(int i=0;i<n-1;i++){
		int a,b; cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int ans=n;
    if(k%2==0){
	    for(int i=0;i<n;i++){
		    int cnt=0;
		    for(int t:G[i]){
			    cnt+=dfs(t,i,k/2);
		    }
    	ans=min(ans,cnt);
    	}
    }
    else{
    	for(int i=0;i<n;i++){
    		for(int t:G[i]){
    			int cnt=dfs(t,i,(k+1)/2)+dfs(i,t,(k+1)/2);
    			ans=min(ans,cnt);
    		}
	    }
    }
	cout << ans << endl;
}