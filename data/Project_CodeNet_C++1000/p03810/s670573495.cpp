#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000000000000

bool dfs(vector<int> A){
	int c = 0;
	for(int i=0;i<A.size();i++){
		c += (A[i]-1)%2;
		c%=2;
	}
	
	if(c==1)return true;
	c += A.size();
	c %= 2;
	if(c==0)return false;
	
	int ind = -1;
	for(int i=0;i<A.size();i++){
		if(A[i]%2==1){
			if(A[i]==1)return false;
			if(ind!=-1)return false;
			ind = i;
			A[i]--;
		}
	}
	int g = 0;
	for(int i=0;i<A.size();i++)g = gcd(A[i],g);
	for(int i=0;i<A.size();i++)A[i]/=g;
	
	if(dfs(A))return false;
	return true;
}

bool dfs2(vector<int> A){
	int c = A[0]+A[1]-2;
	c %= 2;
	if(c==1)return true;
	return false;
}

int main(){
	
	int N;
	cin>>N;
	
	vector<int> A(N);
	for(int i=0;i<N;i++)cin>>A[i];
	
	if(N==1)cout<<"Second"<<endl;
	else if(N==2){
		if(dfs2(A))cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
	else{
		if(dfs(A))cout<<"First"<<endl;
		else cout<<"Second"<<endl;
	}
	
	
	return 0;
}
