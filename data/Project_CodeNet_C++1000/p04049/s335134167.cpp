#include <bits/stdc++.h>
#define max 2010

using namespace std;

void dfs(int a[],int b[],int n,int now,int w[], int kyori);

int main(void)
{
	int n,k; cin>>n>>k;
	int a[n],b[n];
	for(int i = 1; i < n; i++) cin>>a[i]>>b[i];
	int w[n+1][n+1];
	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < n+1; j++){
			w[i][j] = 0;
		}
	}
	for(int i = 1; i < n ; i++){
		w[a[i]][b[i]] = 1; w[b[i]][a[i]] = 1;
		for(int j = 1; j < n + 1; j++){
			if(w[a[i]][j] != 0 && j != b[i]){
				w[b[i]][j] = w[a[i]][j]+1;
				w[j][b[i]] = w[j][a[i]]+1;
			}
			else if(w[b[i]][j] != 0 && j != a[i]){
				w[a[i]][j] = w[b[i]][j]+1;
				w[j][a[i]] = w[j][b[i]]+1;
			}
		}
	}
	/*
	for(int i = 1; i < n+1; i++){
		for(int j = 1; j < n+1; j++){
			cout<<w[i][j]<<" ";
		}
		cout<<endl;
	}
	*/
	//for(int i = 1; i < n+1; i++) dfs(a,b,n,i,w[i],0);
	
	int ans = max;
	if(k % 2 == 0){
		for(int i = 1; i < n + 1; i++){
			int t = 0;
			for(int j = 1; j < n + 1; j++){
				if(k/2 < w[i][j]) t++;
			}
			if(t < ans) ans = t;
		}
	}
	else{
		for(int i = 1; i < n; i++){
			int t = 0;
			for(int j = 1; j < n+1; j++){
				if(w[a[i]][j] < w[b[i]][j]){
					if(w[a[i]][j] > (k-1)/2) t++;
				}
				else{
					if(w[b[i]][j] > (k-1)/2) t++;
				}
			}
			if(t < ans) ans = t;
		}
	}
	cout<<ans<<endl;
	
	return 0;
}

void dfs(int a[],int b[],int n,int now,int w[], int kyori)
{
	//cout<<"now = "<<now<<", kyori = "<<kyori<<endl;
	//for(int i = 1; i < n + 1; i++) cout<<w[i]<<" ";
	//cout<<endl;
	for(int i = 1; i < n; i++){
		if(a[i] == now && w[b[i]] == -1){
			//cout<<" i = "<< i<<", a[i] = "<<a[i]<<", now = "<<now<<", w[i] = "<<w[i]<<endl;
			w[b[i]] = kyori+1;
			dfs(a,b,n,b[i],w,kyori+1);
		}
		else if(b[i] == now && w[a[i]] == -1){
			w[a[i]] = kyori+1;
			dfs(a,b,n,a[i],w,kyori+1);
		}
	}
}


