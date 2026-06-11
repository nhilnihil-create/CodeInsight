
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
  int a, b, c;
  cin>>a>>b>>c;
  int ans = max(a,max(b,c));
  if(ans ==(a+b) || ans == (a+c) || ans == (b+c)){
    cout<<"Yes";
  }
  else{cout<<"No";}
}
