#include<iostream>
#include<cmath>
using namespace std;
#define ll long long
#define mod 1000000007
#define for(i,n) for(int i=0;i<(int)n;i++)
int main(){
	int a,b,c;
  int c_5 = 0,c_7 =0;
  cin>>a>>b>>c;
  if(a==5)c_5++;
    if(a==7)c_7++;
    if(b==5)c_5++;
    if(b==7)c_7++;
    if(c==5)c_5++;
    if(c==7)c_7++;
  if(c_5==2&&c_7==1)cout<<"YES";
  else cout<<"NO";
  return 0;
  
}