#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

int check(vector<vector<int>> &E,int from){
	vector<int> V;
	for(int i=0;i<E[from].size();i++){
		V.push_back(check(E,E[from][i])+1);
	}
	
	sort(V.begin(),V.end());
	int now = 0;
	
	for(int i=0;i<V.size();i++){
		now++;
		if(V[i]>now)now=V[i];
	}
	
	return now;
	
	
}
int main(){
	int N;
	cin>>N;
	
	vector<vector<int>> E(N,vector<int>());
	
	for(int i=0;i<N-1;i++){
		int k;
		cin>>k;
		k--;
		E[k].push_back(i+1);
	}
	
	cout<<check(E,0)<<endl;
	
		
	
	return 0;
}
