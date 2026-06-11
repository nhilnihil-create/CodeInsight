#include <bits/stdc++.h>
using namespace std;
int main(){
  string A;
  cin>>A;
  int ans=0;
  if(A.at(0)!='C')ans++;
  if(A.at(1)!='O')ans++;
  if(A.at(2)!='D')ans++;
  if(A.at(3)!='E')ans++;
  if(A.at(4)!='F')ans++;
  if(A.at(5)!='E')ans++;
  if(A.at(6)!='S')ans++;
  if(A.at(7)!='T')ans++;
  if(A.at(8)!='I')ans++;
  if(A.at(9)!='V')ans++;
  if(A.at(10)!='A')ans++;
  if(A.at(11)!='L')ans++;
  if(A.at(12)!='2')ans++;
  if(A.at(13)!='0')ans++;
  if(A.at(14)!='1')ans++;
  if(A.at(15)!='6')ans++;
  cout<<ans<<endl;
}
