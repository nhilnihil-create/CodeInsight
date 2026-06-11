 #include<bits/stdc++.h>
using namespace std;
int main()
{
  int a[3];
  for(int i=0;i<3;i++)
  {
    cin>>a[i];
  }
  sort(a,a+3);
  int x = a[0]+a[1];
  int y = a[1]+a[2];
  int z = a[0]+a[2];
  
  int ans = min(x,min(y,z));
  cout<<ans<<endl;
}