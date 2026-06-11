#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
  int N;cin>>N;
  int a,b;
  a = N%10;
  b = N/10 %10;
  if (a==9 | b==9) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}