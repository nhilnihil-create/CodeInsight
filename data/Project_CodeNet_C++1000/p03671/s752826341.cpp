#include<bits/stdc++.h>
using namespace std;
vector<int>vec;
//map<int,int>mp;
int main()
{

  int i,j,n,t,a,b,c;
  string s;
  cin>>a>>b>>c;
  int ara[3];
  ara[0]=a;
  ara[1]=b;
  ara[2]=c;
  sort(ara,ara+3);
  cout<<ara[0]+ara[1]<<"\n";


    return 0;
}
