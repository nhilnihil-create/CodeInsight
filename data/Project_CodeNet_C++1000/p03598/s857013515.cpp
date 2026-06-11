#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;
  cin>>n>>k;
  vector<int> x(n);
  for(int i=0; i<n; i++){
    cin>>x.at(i);
  } 
  int sum=0;
  for(int i=0; i<n; i++){
    if(x.at(i)<=(k-x.at(i))){
      sum+=2*x.at(i);
    }
    if(x.at(i)>(k-x.at(i))){
      sum+=2*(k-x.at(i));
    }
  }
    cout<<sum<<endl;
}
