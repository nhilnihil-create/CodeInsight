#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;


int main(){
	int h,w;
	cin>>h>>w;
	string s[27][27];
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin>>s[i][j];
		}
	}
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			if(s[i][j]=="snuke"){
				cout<<(char)('A'+j)<<i+1<<endl;
			}
		}
	}
	return 0;
}
