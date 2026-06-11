#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
    cin>>n;
    vector<long long>a(n);
    vector<long long>b(n);
    for(int i=0;i<n;i++)
    {
      cin>>a[i]>>b[i];
    }
    long long d=0;
    for(int i=n-1;i>=0;i--)
    {
      a[i]+=d;
      if(a[i]%b[i]!=0)
      {
        d+=(((a[i]/b[i])+1)*b[i])-a[i];
      }
    }
    cout<<d<<endl;
    return 0;
}