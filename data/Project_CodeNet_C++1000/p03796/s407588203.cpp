 #include<bits/stdc++.h>
using namespace std;
long A[22];
int main()
{
   long long a,b,n,i,r=1;
   cin>>n;
   for(i=1;i<=n;i++)
   {
      r*=i;
      r=r%1000000007;
   }
   cout<<r<<endl;
}
