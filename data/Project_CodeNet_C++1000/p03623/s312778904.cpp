#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,b;cin>>n>>a>>b;
  if(max(a-n,n-a)<max(n-b,b-n)){
cout<<"A"<<endl;
  }else cout<<"B"<<endl;
}
