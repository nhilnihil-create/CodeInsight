#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000
vector<long long> A;
long long check(vector<vector<int>> &E,int now,int parent){
	if(E[now].size()==1&&parent!=-1){
		return A[now];
	}
	vector<long long> V;
	for(int i=0;i<E[now].size();i++){
		int to = E[now][i];
		if(to==parent)continue;
		V.push_back(check(E,to,now));
	}
	long long sum = 0;
	long long maxi = 0;
	for(int i=0;i<V.size();i++){
		if(V[i]==-1)return -1;
		sum += V[i];
		maxi = max(maxi,V[i]);
	}
	
	long long K = sum-A[now];
	if(K<0)return -1;
	if(min(sum/2,sum-maxi)<K){
		return -1;
	}
	
	return A[now] - K;
	
}

int main(){
	long long N;
	cin>>N;
	for(int i=0;i<N;i++){
		long long a;cin>>a;
		A.push_back(a);
	}
	vector<vector<int>> E(N,vector<int>(0));
	vector<int> ji(N,0);
	for(int i=0;i<N-1;i++){
		int a,b;
		cin>>a>>b;
		a--;b--;
		E[a].push_back(b);
		E[b].push_back(a);
		ji[a]++;ji[b]++;
	}
	int f;
	for(int i=0;i<N;i++){
		if(ji[i]==1){
			f = i;
			break;
		}
	}
	
	int k = check(E,f,-1);
	//cout<<k<<endl;
	if(k!=A[f]){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
	}
	
	
	
	
	return 0;
}
