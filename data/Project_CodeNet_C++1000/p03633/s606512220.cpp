#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  int n;
  cin>>n;


  int64_t out=1;
  for(int i=0;i<n;i++){
    int64_t t;
    cin>>t;

    out=lcm(out,t);
  }

  cout<<out<<endl;

	return 0;
}