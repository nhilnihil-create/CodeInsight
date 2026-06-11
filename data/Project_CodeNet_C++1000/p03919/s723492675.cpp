#include<bits/stdc++.h>
using namespace std;
 
int main(){
	string s[26][26];
	int h,w;
	cin>>h>>w;

	int number;
	char c;
	for (int i = 0; i < h; i++){
		for (int j = 0; j < w; j++){
			cin>>s[i][j];
			if(s[i][j]=="snuke"){
				c='A'+j;
				number=i+1;
			}
		}
	}

	cout<<c<<number<<endl;
}