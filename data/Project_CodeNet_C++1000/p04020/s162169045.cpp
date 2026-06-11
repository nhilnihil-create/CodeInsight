#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  cin>>n;
  vector<long long >nos(n,0);
  for(int i=0;i<n;i++)cin>>nos[i];
  long long count=0,sum=0;
  for(int i=0;i<n;i++){
    if(nos[i]==0){count+=sum/2;sum=0;continue;}
    sum+=nos[i];
  }
  count+=sum/2;
  cout<<count;
}