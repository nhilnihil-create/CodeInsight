#include <bits/stdc++.h>
using namespace std;
#define modulo 1000000007
#define mod(mod_x) ((((long long)mod_x+modulo))%modulo)
#define Inf 10000000


int main(){

	int H,W,N;
	cin>>H>>W>>N;
	
	vector<int> a(N);
	for(int i=0;i<N;i++){
		cin>>a[i];
	}
	
	vector<vector<int>> ans(H,vector<int>(W));
	
	int y = 0;
	int x = 0;
	
	for(int i=0;i<N;i++){
		for(int j=0;j<a[i];j++){
			ans[y][x]=i+1;
			if(y%2==0){
				x++;
				if(x==W){
					x--;
					y++;
				}
			}
			else{
				x--;
				if(x==-1){
					x++;
					y++;
				}
			}
		}
	}
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(j!=0)cout<<' ';
			cout<<ans[i][j];
		}
		cout<<endl;
	}
	
    return 0;
}

