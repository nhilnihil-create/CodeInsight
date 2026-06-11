#include <iostream>
using namespace std;

int main(){
	int n,m;
	cin>>n>>m;
	int degree[n+1] = {0};

	for(int i=0; i<m; i++){
		int a,b;
		cin>>a>>b;
		degree[a-1]+=1;
		degree[b-1]+=1;
	}

	for(int i=0; i<n; i++){
		cout<<degree[i]<<endl;
	}
}