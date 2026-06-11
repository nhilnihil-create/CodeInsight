#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	int n;cin>>n;
	vector<int>v[n+1];
	int dst[n+1];bool vstd[n+1];
	for(int i=1;i<=n;i++){
		int a;cin>>a;
		v[i].push_back(a);
	}
	memset(vstd,0,sizeof vstd);
	memset(dst,0,sizeof dst);
	queue<int>q;
	q.push(1);
	while(q.size()){
		int node=q.front();
		q.pop();
		if(vstd[node])continue;
		vstd[node]=true;
		for(auto u:v[node]){
			if(!vstd[u]){
				dst[u]=dst[node]+1;
				q.push(u);
			}
		}
	}
	if(dst[2]){
		cout<<dst[2];
	}else{
		cout<<-1;
	}
}