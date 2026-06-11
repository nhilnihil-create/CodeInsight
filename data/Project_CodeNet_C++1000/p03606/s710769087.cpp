#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> x(n);
  vector<int> y(n);
  for(int i=0;i<2*n;i++){
    cin>>x[i]>>y[i];
  }
  int sum=0;
  for(int i=0;i<n;i++){
    sum+=y[i]-x[i]+1;
  }
  cout<<sum<<endl;
}