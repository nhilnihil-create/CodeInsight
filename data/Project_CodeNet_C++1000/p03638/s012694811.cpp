#include <bits/stdc++.h>
using namespace std;
int grid[105][105];
int main(){
	int n , m , k;
	cin>>n>>m>> k;
	vector<int>vi;
	for(int i= 0; i < k ; i++){
		int x ;cin>>x;
		vi.push_back(x);
	}
	int curr = 0 ,cnt = 0;
	for(int i =0 ; i < m ; i++){
		if(i%2==0){
			for(int j = 0; j < n ;j++){
				grid[j][i] = curr+1;
				cnt++;
				if(cnt == vi[curr]){
					curr++;
					cnt = 0;
				}
			}
		}else{
			for(int j = n-1 ; j >= 0; j--){
				grid[j][i] = curr+1;
				cnt++;
				if(cnt == vi[curr]){
					curr++;
					cnt = 0;
				}			
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0;j < m ;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
	return 0;
}

