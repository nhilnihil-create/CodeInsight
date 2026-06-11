#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;cin>>n>>k;
  long long answer=k;
  for(int i=1;i<n;i++){
  	answer*=(k-1);
  }
  cout<<answer;
}