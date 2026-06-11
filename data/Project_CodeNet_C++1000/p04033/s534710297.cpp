#include <bits/stdc++.h>
using namespace std;

int A,B;

int main(){
	cin>>A>>B;
	if(A<=0&&B>=0){
		cout<<"Zero"<<'\n';
	}else if(A>0&&B>0){
		cout<<"Positive"<<'\n';
	}else{
		if((B-A)%2==0){
			cout<<"Negative"<<'\n';
		}else{
			cout<<"Positive"<<'\n';
		}
	}
}