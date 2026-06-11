#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n);
  for(int i=0;i<n;i++)
    cin>>a.at(i);
  vector<int> b;
  for(int i=1;i<n;i+=2)
    b.push_back(a.at(i));
  reverse(b.begin(),b.end());
  for(int i=0;i<n;i+=2)
    b.push_back(a.at(i));
  if(n%2==1)
    reverse(b.begin(),b.end());
  for(int i=0;i<n;i++)
    cout<<b.at(i)<<(i+1<n?" ":"");
  cout<<endl;
}