#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,j=1;
	bool b=0,c=0;
	cin>>a;
	int ant;
	cin>>ant;
	for(int i=0;i<a-1;i++){
		int actual;
		cin>>actual;
		if(actual>ant){
			b=true;
		}
		if(actual<ant){
			c=true;
		}
		if(b && c){
			j++;
			b=false;
			c=false;
		}
		ant=actual;
	}
	cout<<j<<endl;
	return 0;
}