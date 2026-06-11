#include<bits/stdc++.h>
using namespace std;
int main()
{
   int N,L,i;
   string x;
   vector<string>z;
   cin>>N>>L;
   for(i=0;i<N;i++)
   {
       cin>>x;
       z.push_back(x);
   }
   sort(z.begin(),z.end());
   for(i=0;i<N;i++)
   {
       cout<<z[i];
   }

}
