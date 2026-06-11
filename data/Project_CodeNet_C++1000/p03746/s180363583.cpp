#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000


int main(){
	
	int N,M;
	cin>>N>>M;
	
	vector<vector<int>> E(N,vector<int>());
	
	for(int i=0;i<M;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		
		E[a].push_back(b);
		E[b].push_back(a);
	}
	
	vector<bool> checked(N,false);
	
	deque<int> ans;
	ans.push_back(0);
	ans.push_back(E[0][0]);
	
	checked[0]=true;
	checked[E[0][0]]=true;
	
	while(true){
		int from = ans[0];
		int to = ans[ans.size()-1];
		
		bool f = true;
		for(int i=0;i<E[from].size();i++){
			if(checked[E[from][i]]==false){
				ans.push_front(E[from][i]);
				checked[E[from][i]]=true;
				f=false;
				break;
			}
		}
		
		for(int i=0;i<E[to].size();i++){
			if(checked[E[to][i]]==false){
				ans.push_back(E[to][i]);
				checked[E[to][i]]=true;
				f=false;
				break;
			}
		}
		
		if(f)break;
	}
	
	cout<<ans.size()<<endl;
	
	for(int i=0;i<ans.size();i++){
		if(i!=0)cout<<' ';
		cout<<ans[i]+1;
	}
	
	return 0;
}

