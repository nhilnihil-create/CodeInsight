#include<bits/stdc++.h>
using namespace std;
int main(){
	int h,w;
	cin>>h>>w;
	int n;
	cin>>n;
	int color[n+1];
	for(int i=1; i<=n; i++) cin>>color[i];
	int arr[h+1][w+1]={0};
	int col = 0;
	int p = 1;
	for(int i=1; i<=h; i++){
		if(col==0){
			for(int j=1; j<=w; j++){
				arr[i][j] = p;
				color[p]--;
				if(color[p]==0) p++; 
			}
			col = w+1;
		}
		else{
			for(int j=w; j>=1; j--){
				arr[i][j] = p;
				color[p]--;
				if(color[p]==0) p++;
			}
			col = 0;
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++) cout<<arr[i][j]<<" ";
		cout<<'\n';
	}
}