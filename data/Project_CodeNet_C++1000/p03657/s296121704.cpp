#include<bits/stdc++.h>
 
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int a,b;
	cin>>a>>b;
	if(a%3 && b%3 && (a+b)%3){
		cout<<"Impossible"<<endl;
	}
	else
		cout<<"Possible"<<endl;

	return 0;
}
