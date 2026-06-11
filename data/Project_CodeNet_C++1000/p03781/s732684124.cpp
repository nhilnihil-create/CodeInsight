#include<iostream>
using namespace std;
//const int mod = 1e9 + 7;

int main(){
 long long n,sum=0;
 cin>>n;
 int i;
 
 for(i=0;sum<n;i++)
 sum+=i;
 cout<<i-1<<endl; 
	
	
	return 0;
} 