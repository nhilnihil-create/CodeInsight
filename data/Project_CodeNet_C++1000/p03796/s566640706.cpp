#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int main(){
	long long int n;
  	cin>>n;
  	long long int pw=1;
  	long long int a=1000000000+7;
  	for(long long int i=1;i<=n;i++){
    	i =i%a;
      pw *=i;
      pw =pw%a;
    }
  	
  	cout<< pw <<endl;
}
