#include<bits/stdc++.h>
using namespace std;
int main()
{
  string n;	
  int s=0; 
  cin>>n;
  if(n[0]!='C') 
    s++;
  if(n[1]!='O')
    s++;
  if(n[2]!='D') 
    s++;
  if(n[3]!='E') 
    s++;
  if(n[4]!='F') 
    s++;
  if(n[5]!='E') 
    s++;
  if(n[6]!='S') 
    s++; 
  if(n[7]!='T') 
    s++;
  if(n[8]!='I') 
    s++;
  if(n[9]!='V') 
    s++;
  if(n[10]!='A') 
    s++;
  if(n[11]!='L') 
    s++;
  if(n[12]!='2') 
    s++;
  if(n[13]!='0') 
    s++;
  if(n[14]!='1') 
    s++;
  if(n[15]!='6') 
    s++;
  cout<<s<<endl;
  return 0;
}