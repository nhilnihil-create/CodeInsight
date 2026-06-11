#include<bits/stdc++.h>
#define ll long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main()
{
    FAST();
    ll n,i,j,k,a,b;
  map<ll,ll>m;
  m[1]=1;
  m[3]=1;
  m[5]=1;
  m[7]=1;
  m[8]=1;
  m[10]=1;
  m[12]=1;
  m[4]=2;
  m[6]=2;
  m[9]=2;
  m[11]=2;
  m[2]=3;
  cin>>a>>b;
  if(m[a]==m[b])
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;


    return 0;
}
