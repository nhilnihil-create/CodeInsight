#include<bits/stdc++.h>
using namespace std;
long long av[100100];

int main(void)
{
  long long n,i, c[5]={0},c0,c2,c4;
  cin >> n;
  for(i=0;i<n;i++){
    cin>>av[i];
    c[av[i]%4]++;
  }
  c0=c[1]+c[3]+((c[2]>0)?1:0);
  c2=c[2];
  c4=c[0];
  cout<<((c0-c4<2)?"Yes":"No");
  
 
  //スマホから提出

}