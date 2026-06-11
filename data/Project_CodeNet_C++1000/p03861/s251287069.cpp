#include <bits/stdc++.h>

using namespace std;

int main(){

  long long int a, b, x;
  cin>>a>>b>>x;

  long long int count=0;
  count=(b/x)-(a/x);

  if(a%x==0) count+=1;
  else if(a==0) count+=1;

  cout<<count<<endl;
}
