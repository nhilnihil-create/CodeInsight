#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;
int INF=1<<29;

int main(){
	ios::sync_with_stdio(false);
	int N;
	string s;
	vector<string> arr={"SS","SW","WS","WW"};
	cin>>N>>s;
	for(int j=0;j<4;j++){
		for(int i=2;i<N;i++){
			if(arr[j][i-1]=='S'){
				if(s[i-1]=='o') arr[j]+=arr[j][i-2];
				else{
					if(arr[j][i-2]=='S') arr[j]+='W';
					else arr[j]+='S';
				}
			}else{
				if(s[i-1]=='x') arr[j]+=arr[j][i-2];
				else{
					if(arr[j][i-2]=='S') arr[j]+='W';
					else arr[j]+='S';
				}
			}
		}
		//cout<<arr[j]<<" ";
		bool check=true;
		for(int i=0;i<N;i++){
			if(i==0){
				if(arr[j][i]=='S'){
					if(s[i]=='o'){
						if(arr[j][N-1]!=arr[j][i+1]) check=false;
					}else{
						if(arr[j][N-1]==arr[j][i+1]) check=false;
					}
				}else{
					if(s[i]=='x'){
						if(arr[j][N-1]!=arr[j][i+1]) check=false;
					}else{
						if(arr[j][N-1]==arr[j][i+1]) check=false;
					}
				}
				continue;
			}
			if(i==N-1){
				if(arr[j][i]=='S'){
					if(s[i]=='o'){
						if(arr[j][i-1]!=arr[j][0]) check=false;
					}else{
						if(arr[j][i-1]==arr[j][0]) check=false;
					}
				}else{
					if(s[i]=='x'){
						if(arr[j][i-1]!=arr[j][0]) check=false;
					}else{
						if(arr[j][i-1]==arr[j][0]) check=false;
					}
				}
				continue;
			}
			if(arr[j][i]=='S'){
				if(s[i]=='o'){
					if(arr[j][i-1]!=arr[j][i+1]) check=false;
				}else{
					if(arr[j][i-1]==arr[j][i+1]) check=false;
				}
			}else{
				if(s[i]=='x'){
					if(arr[j][i-1]!=arr[j][i+1]) check=false;
				}else{
					if(arr[j][i-1]==arr[j][i+1]) check=false;
				}
			}
		}
		if(check){
			cout<<arr[j]<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}