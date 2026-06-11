#include<bits/stdc++.h>
using namespace std;
int n;
char arr[2][55];
int moder = 1000000007;
int main(){
	cin>>n>>arr[0]+1>>arr[1]+1;
	int p = 1;
	vector<int>tile;
	while(p<=n){
		if(arr[0][p]==arr[1][p]){
			tile.push_back(2);
			p++;
		}
		else{
			tile.push_back(1);
			p+=2;
		}
	}
	long long ret = 1;
	for(int i=0; i<tile.size(); i++){
		if(i==0){
			if(tile[i]==1) ret*=6;
			else ret*=3;
		}
		else{
			if(tile[i]==1){
				if(tile[i-1]==1) ret*=3;
				else ret*=2;
			}
			else{
				if(tile[i-1]==1) ret*=1; 
				else ret*=2;
			}
		}
		ret%=moder;
	}
	cout<<ret;
}