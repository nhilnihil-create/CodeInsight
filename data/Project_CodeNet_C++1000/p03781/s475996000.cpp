#include<iostream>
using namespace std;
int main(){
	int x;
	cin>>x;
	int sum=0;
	int count=0;
	int i=1;
	while(sum<x){
		sum+=i;
		count++;
		i++;
	}
	cout<<count;
	return 0;
}