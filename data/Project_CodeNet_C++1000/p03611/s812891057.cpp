#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >count(100000,0);
  for(int i=0,a;i<n;i++){cin>>a;count[a]++;}
  //for each number I want the nearest neighbours
  int maxi=0;
  int curr=0;
  for(int i=0;i<100000;i++){
  	curr = 0;
    curr+=count[i];
    if(i-1>=0)curr+=count[i-1];
    if(i+1 < 100000)curr+=count[i+1];
    maxi = max(maxi,curr);
  }
  cout<<maxi;
}