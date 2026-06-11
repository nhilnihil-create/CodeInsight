#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  	int n;
  	cin >> n;
  	int a[n],sum=0;
  	for(int i=0;i<n;i++)
    {cin >> a[i]; sum+=a[i];}

  	int m,t;
  	cin >> m;
  	for(int i=0;i<m;i++){
      t=sum;
      int x,y;
      cin >> x >> y;
      t = sum-a[x-1]+y;
      cout << t <<"\n";
    }
    return 0;
}