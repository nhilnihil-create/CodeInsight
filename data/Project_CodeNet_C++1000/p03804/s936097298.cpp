#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ll long long
#define llmax LLONG_MAX   //ranges are defined in climits
#define llmin LLONG_MIN
#define imax INT_MAX
#define imin INT_MIN
#define pb push_back
int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL);
  int n,m;cin>>n>>m;
  char a[n][n],b[m][m];
  int i,j;
  for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      cin>>a[i][j];
  for(i=0;i<m;i++)
    for(j=0;j<m;j++)
      cin>>b[i][j];
  bool ans=true;
  for(i=0;i+m<=n;i++)
  {
    for(j=0;j+m<=n;j++)
    {
      bool found=true;
      for(int x=0;x<m && found;x++)
      {
        for(int y=0;y<m;y++)
        {
          if(a[i+x][j+y]!=b[x][y])
          {
            found=false;
            break;
          }
        }
      }
      if(found)
      {
        cout<<"Yes";return 0;
      }
    }
  }
  cout<<"No";
	return 0;
}
