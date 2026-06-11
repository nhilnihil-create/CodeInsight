#include <bits/stdc++.h>
using namespace std;

int main(){
	int n,a,b;
	cin >> n >> a >> b;
	int qAll = a+b;
	int qForeign = b;
	string s;
	cin.ignore();
	getline(cin, s, '\n');
	for(int i=0;i<n;i++){
		if(s[i]=='c'){
			printf("No\n");
		}else if(s[i]=='a'){
			if(qAll>0){
				qAll--;
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}else{
			if(qAll > 0 && qForeign > 0){
				qAll--;
				qForeign--;
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}
}