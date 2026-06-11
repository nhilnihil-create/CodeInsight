#include<iostream>
using namespace std;
int main(){
	string in,b="CODEFESTIVAL2016";
	int sum;
	cin>>in;
	for(int i=0;i<in.length();i++)if(in[i]!=b[i])sum++;
	cout<<sum<<endl;
}
