#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

#define show(x) cerr << #x << " = " << x << endl;


int main()
{

  int a, b;
  cin>>a>>b;

  if((a+b)>=10)
  {
    string ans = "error";
    cout<< ans<<endl;
  }
  else
  {

    int ans = a+b;
    cout<< ans<<endl;
  }




  return 0;
}
