#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>

#define MAX_V 100010
using namespace std;
vector<int> G[MAX_V];
vector<pair<int,int>> toi;
stack<int> st;
bool used[MAX_V];
int d[MAX_V],a[MAX_V],V;

void dfs(int s){
	used[s] = true;
	st.push(s);
	while(!st.empty()){
		int e = st.top();
		st.pop();
		for(int i=0;i<G[e].size();i++){
			if(!used[G[e][i]]){
				used[G[e][i]] = true;
				d[G[e][i]] = d[e]+1;
				st.push(G[e][i]);
			}
		}
		
	}
}

void dfs1(int s){
	used[s] =false;
	st.push(s);
	while(!st.empty()){
		int e = st.top();
		st.pop();
		for(int i=0;i<G[e].size();i++){
			if(used[G[e][i]]){
				used[G[e][i]] = false;
				st.push(G[e][i]);
			}
		}
	}
}
	
int main(){
	int i,j,k,ans=0,cnt,x,y;
	cin >> V >> k;
	cin >> i;
	if(i!=1){
		ans++;
	}
	for(i=1;i<V;i++){
		cin >> a[i];
		a[i]--;
		G[a[i]].push_back(i);
	}

	for(i=0;i<V;i++){
		G[i].push_back(-1);
		used[i] = false;
		d[i] = 0;
	}
	dfs(0);

	for(i=0;i<V;i++){
		if(d[i]>k){
			toi.push_back(make_pair(d[i],i));
		}
	}
	sort(toi.begin(),toi.end());

	for(i=toi.size()-1;i>=0;i--){
		if(used[toi[i].second]){
			ans ++;
			cnt = 0;
			x = toi[i].second;
			while(cnt<k-1){
				cnt++;
				y = a[x];
				x = y;
			}
			dfs1(x);
		}
	}
	cout << ans << endl;
}
