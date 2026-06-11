#include <bits/stdc++.h>
using namespace std;
 
 
int main() {
 
  string n;
  cin>>n;

  string n_org=n;
  reverse(n.begin(),n.end());

  if(n==n_org)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

	return 0;
}