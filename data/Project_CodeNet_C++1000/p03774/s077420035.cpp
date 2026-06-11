#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
long long int power(int a,int b)
{
    if(b==0)
        return 1;
    long long int k=power(a,b/2);
    if(b%2==0)
        return ((k%M)*(k%M))%M;
    else
        return ((k%M)*(k%M)*(a%M))%M;
}
long long int fact(long long int n)
{
    if(n==1 || n==0)
        return 1;
    else
        return ((n%M)*(fact(n-1)%M))%M;

}
int div(int n)
{  int c=0;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i==0)
        {
          if(n/i==i)
            c++;
          else
            c+=2;
        }

    }

    
    return  c;
}
int func(int n)
{
    return (n*(n+1))/2;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
   #endif
   
   int n,m;
   cin>>n>>m;
   vector<pair<int,int> > v,v1; 
   for(int i=1;i<=n;i++)
   {  
    int a,b;
    cin>>a>>b;
      v.push_back(make_pair(a,b));
   }
   for(int i=1;i<=m;i++)
   {
    int a,b;
    cin>>a>>b;
    v1.push_back(make_pair(a,b));
   }
   for(int i=0;i<n;i++)
   { 
          int cmin=INT_MAX;
          int idx;
         for(int j=0;j<m;j++)
         {
            int diff=abs(v1[j].first - v[i].first) + abs(v1[j].second - v[i].second);
            if(cmin>diff)
            {
                cmin=diff;
                idx=j+1;
            }
         }
         cout<<idx<<endl;
   }




 return 0;
}






