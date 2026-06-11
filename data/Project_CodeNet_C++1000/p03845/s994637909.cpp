# include<bits/stdc++.h>
# define ull unsigned long long int
using namespace std;
int main()
{
   int n;
   cin>>n;
   vector<int>ar;
   ull sum=0;
   for(int i=0;i<n;i++)
   {
     int val;
     cin>>val;
     ar.push_back(val);
     sum+=ar[i];
    }
    int m;
    cin>>m;
    while(m--)
    {
      ull p,x;
      cin>>p>>x;
      ull out=sum-ar[p-1]+x;
      cout<<out<<endl;
    }

}