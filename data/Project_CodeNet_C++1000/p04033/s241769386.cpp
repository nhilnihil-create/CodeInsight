#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;

int main()
{
       ios_base::sync_with_stdio(0);
       cin.tie(0);

       int t=1;
       //cin>>t;
       while(t--)
       {
               int a,b;
               cin>>a>>b;
               if(a>0)
                    cout<<"Positive";
               else if(a<=0 && b>=0)
                    cout<<"Zero";
               else
               {
                    if(a<0 && b==0)
                    {
                         a = abs(a);
                         if(a%2)
                              cout<<"Negative";
                         else
                              cout<<"Positive";
                    }
                    else
                    {
                         a = abs(a);
                         b = abs(b);
                         int ans = a-b;
                         if(ans%2)
                              cout<<"Positive";
                         else
                              cout<<"Negative";
                    }
               }
       }
}
