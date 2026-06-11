#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,m,k;
	cin >> n >> m >> k;
	bool flag = false;
	for(int a=0;a<=m;a++){
		for(int b=0;b<=n;b++){
			if(b*(m-a)+a*(n-b) == k){
				flag = true;
			}
		}
	}
	if(flag){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}
