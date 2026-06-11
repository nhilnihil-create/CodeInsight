 #include<bits/stdc++.h>
#define ull unsigned long long int
using namespace std;
int main()
  {
  ull n,sum=1,m = 1000000007;
  cin>>n;
  for(ull i = 1;i<=n;i++)
    {
    sum = (sum * i)%m;
   }
  cout<<sum<<endl;
  }