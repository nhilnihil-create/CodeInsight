#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
  int A,B,C,fg=0;
  cin>>A>>B>>C;
  if(A==5 && B==5 && C==7)
    fg=1;
  else if(A==5 && B==7 && C==5)
    fg=1;
  else if(A==7 && B==5 && C==5)
    fg=1;
  else
    fg=0;
  if(fg==1)
    cout<<"YES"<<'\n';
  else
    cout<<"NO"<<'\n';
}
