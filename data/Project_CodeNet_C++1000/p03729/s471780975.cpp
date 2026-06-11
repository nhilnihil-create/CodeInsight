#include<bits/stdc++.h>
#include<stdio.h>

using namespace std;

#define show(x) cerr << #x << " = " << x << endl;

int main()
{
  string a, b, c;

  cin>>a>>b>>c;

  bool AB = (a[a.size()-1] == b[0])? true: false;
  bool BC = (b[b.size()-1] == c[0])? true: false;

  if(AB && BC)
  {
    cout<<"YES"<<endl;
  }
  else
  {
    cout<<"NO"<<endl;
  }


  return 0;
}
