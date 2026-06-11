 #include<bits/stdc++.h>
using namespace std;
long A[22];
int main()
{
   long long a,b,c,n,i,m;
   map<int,int>M;
   std::cin >>n>>m;
   while(m--)
   {
     cin>>a>>b;
     M[a]++;
     M[b]++;
 }
 for(i=1;i<=n;i++)
 cout<<M[i]<<endl;
}
