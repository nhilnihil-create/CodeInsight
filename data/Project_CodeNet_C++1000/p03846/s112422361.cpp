#include<bits/stdc++.h>
using namespace std;
const int m=1e9+7;
#define int long long int 
int cal(int x,int y)
{
    int res=1;
    while(y>0)
    {
        if(y&1)
        res=(res*x)%m;
        x=(x*x)%m;
        y=y>>1;
    }
    return res%m;
}
int32_t main(){

    int n;
    cin>>n;
    set<int> s;
    if(n&1)
    {
        int i=0;
        while(i<n)
        {
            s.insert(i);
            i+=2;
        }
    }
    else
    {
        int i=1;
        while(i<n)
        {
            s.insert(i);
            i+=2;
        }
    }

   map<int,int> m;
   for(int i=0;i<n;i++)
   {
       int x;
       cin>>x;
       m[x]++;
   }

    int f=0;
    int power=0;
   for(auto i:m)
   {
       if((m[i.first]!=2||s.find(i.first)==s.end())  && i.first!=0)
       {
           f=1;
           break;
       }
       if(i.first!=0)
       power++;

   }
   if(f)
   cout<<0<<endl;  
   else
    cout<<cal(2,power)<<endl;

   

}