#include<bits/stdc++.h>
using namespace std;
const int INF = 1000000000;
int arr[205][205];

int main(){
	int n,m,r;
	cin>>n>>m>>r;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++) arr[i][j] = INF;
	}
	
	vector<int>town(r);
	for(int i=0; i<r; i++) cin>>town[i];
	sort(town.begin(),town.end());
	
	while(m--){
		int a,b,c;
		cin>>a>>b>>c;
		arr[a][b] = min(arr[a][b],c);
		arr[b][a] = min(arr[b][a],c);
	}
	for(int k=1; k<=n; k++){
		for(int i=1; i<=n; i++){
			for(int j=1; j<=n; j++){
				arr[i][j] = min(arr[i][j],arr[i][k]+arr[k][j]);
			}
		}
	}
	int mindist = numeric_limits<int>::max();
	do{
		int dist = 0;
		for(int i=1; i<r; i++) dist+=arr[town[i-1]][town[i]];
		mindist = min(mindist,dist);
	}while(next_permutation(town.begin(),town.end()));
	cout<<mindist;
}