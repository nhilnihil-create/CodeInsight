#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  cin>>n;
  vector<int >nos(3*n,0);
  for(int i=0;i<3*n;i++)cin>>nos[i];
  sort(nos.rbegin(),nos.rend());
  long long sum=0;
  int count=0;
  for(int i=1;i<3*n && count<n;i+=2,count++)sum+=nos[i];
  cout<<sum;
}