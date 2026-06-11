#include<iostream>
using namespace std;
int main(){
	
		int n;
		cin>>n;
		int p =n;
		int temp = 0 ,r =0;
		while(p!=0){
			temp = p%10;
			r = r*10 + temp;
			p = p/10;
		}
		if(r==n){
			cout<<"Yes\n";
		}
		else
			cout<<"No\n";
}