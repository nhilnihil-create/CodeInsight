#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int n,k;
  cin>>n>>k;

  vector<int> L(n);
  for(int i=0;i<n;i++){
    cin>>L.at(i);
  }

  sort(L.begin(),L.end(),greater<int>());

  int64_t sum=0;
  for(int i=0;i<k;i++){
    sum+=L.at(i);
  }

  cout<<sum<<endl;
 

	return 0;
}