#include<bits/stdc++.h>
using namespace std;

#define ll long long

signed main()
{
  int a,b;
  cin >> a >> b;
  a%3==0||b%3==0||(a+b)%3==0? cout<<"Possible" : cout<<"Impossible";
}