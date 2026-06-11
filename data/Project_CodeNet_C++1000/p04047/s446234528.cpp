#include<bits/stdc++.h>
using namespace std;

int a[10100],answer=0,n;

int main()
{
  cin>>n;
  for(int i=1; i<=2*n; i++)
    cin>>a[i];
  sort(a+1,a+1+2*n);
  for(int i=1; i<=2*n; i+=2)
    answer+=a[i];
  cout<<answer<<endl;
  return 0;
}