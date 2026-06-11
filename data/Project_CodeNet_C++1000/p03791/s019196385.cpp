#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> x(n);
  for(int i=0;i<n;i++)
    cin>>x.at(i);
  int p=1000000007;
  int k=0;
  vector<int> c(n,0);
  for(int i=0;i<n;i++){
    if(i+1-k>(x.at(i)+1)/2){
      c.at(k)=i+1-k;
      k++;
    }
  }
  for(int i=k;i<n;i++)
    c.at(i)=n-i;
  int64_t a=1;
  for(int i=0;i<n;i++)
    a=a*c.at(i)%p;
  cout<<a<<endl;
}