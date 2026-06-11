#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(void){
	int h,w;
	cin>>h>>w;
	int ans;
	string s="snuke";
	string a;
	for(int i=0;i<h*w;i++){
		cin>>a;
		if(a==s){
			ans=i;
		}
	}
	int b,c;
	b=ans/w+1;
	c=ans%w;
	char d='A'+c;
	cout<<d<<b<<endl;
	return 0;
}