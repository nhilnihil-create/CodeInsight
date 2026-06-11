#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,a,b;
  cin>>n>>a>>b;
  if(b<a){cout<<0;return 0;}
  if(n==1 && a==b){cout<<1;return 0;}
  else if(n==1 && a!=b){cout<<0;return 0;}
  //now there can be a lot of2 4 8 - lower_sum higher sum;
  //3 4 8 - 4 5 8 4 6 8 4 6 8 4 4 8 4 8 8 - 5 different sums
  //4 4 8 - 4 4 4 8 - 4 8 8 8 - 
  long long minsum = (n-1)*a+b;
  long long maxsum = (n-1)*b+a;
  cout<<maxsum-minsum+1;
  
}