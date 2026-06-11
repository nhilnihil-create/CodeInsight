#include<bits/stdc++.h>
using namespace std;
#define lli long long
#define llmax LLONG_MAX   //ranges are defined in climits
#define llmin LLONG_MIN
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
  int sx,sy,tx,ty;cin>>sx>>sy>>tx>>ty;
  for(int i=0;i<(ty-sy);i++)  cout<<"U";
  for(int i=0;i<(tx-sx);i++)  cout<<"R";
  for(int i=0;i<(ty-sy);i++)  cout<<"D";
  for(int i=0;i<(tx-sx);i++)  cout<<"L";

  cout<<"L";
  for(int i=0;i<=(ty-sy);i++)  cout<<"U";
  for(int i=0;i<=(tx-sx);i++)  cout<<"R";
  cout<<"D";
  cout<<"R";
  for(int i=0;i<=(ty-sy);i++)  cout<<"D";
  for(int i=0;i<=(tx-sx);i++)  cout<<"L";
  cout<<"U";
	return 0;
}