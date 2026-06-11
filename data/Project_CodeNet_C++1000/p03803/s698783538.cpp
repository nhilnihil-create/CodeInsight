#include <bits/stdc++.h> 
using namespace std; 
int main(){
	int a,b;
	cin>>a>>b;
	int flag = 0;
	if(a == 1 && b !=1){
		cout<<"Alice"<<endl;
		flag = 1;
	}else if(b == 1 && a !=1){
		cout<<"Bob"<<endl;
		flag = 1;
	}else if(a==1 && b==1){
		cout<<"Draw"<<endl;
		flag = 1;
	}
	if(flag == 0){
		if(a > b){
			cout<<"Alice"<<endl;
		}else if(b > a){
			cout<<"Bob"<<endl;
		}else{
			cout<<"Draw"<<endl;
		}
	}
	
}
