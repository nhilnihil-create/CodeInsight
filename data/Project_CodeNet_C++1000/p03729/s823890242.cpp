#include<iostream>
#include<string>
using namespace std;
int main()
{
  string a,b,c;
  cin>>a>>b>>c;
  int d,e;
  d=a.size();
  e=b.size();
  if(a[d-1]==b[0]&&b[e-1]==c[0]){
    cout<<"YES";
  }
  else{
    cout<<"NO";
  }
}
