#include<bits/stdc++.h>
using namespace std;
 
#define ll long long
 
signed main()
{
  int x,t; cin >> x >> t;
  if(x<t){
    cout << "0" << "\n";
    return 0;
  }
  else{
  cout << (x-t) << "\n";
  }
}