#include<bits/stdc++.h>
using namespace std;
int main(){
	int k,n;cin>>k>>n;
  int count=0;
  for(int x=0;x<=k;x++)
    for(int y=0;y<=k;y++){
      int z = n - (x+y);
  	if(z<=k && z>=0)count++;}
  cout<<count;
}