#include<bits/stdc++.h>
using namespace std;
int main(){
	int row,col;string s;
	cin >> row >> col;
	for(int i=0; i<row; i++)for(int j=0; j<col; j++){
		cin>>s;
		if(s == "snuke"){
			printf("%c%d\n",j+'A',i+1);
		}
	}
	return 0;
}
