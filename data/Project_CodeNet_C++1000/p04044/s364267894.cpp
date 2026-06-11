#include<iostream>
#include<math.h>
#include<string>
#include<bits/stdc++.h>
using namespace std;

int main()
{
string n[120];
  int a,b;
  cin >> a >> b;
  for(int i = 0;i < a;i++){
    cin >> n[i];
  }
  sort(n,n+a);
  for(int i = 0;i < a;i++){
    cout << n[i];
  }
  cout << endl;
return 0;
}