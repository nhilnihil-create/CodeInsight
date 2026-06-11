#include<bits/stdc++.h>
#define ll long long int
#define FAST() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
using namespace std;
int main()
{
    FAST();
    ll n,i,j,k=1,a,b,x;
   cin>>x>>a>>b;
   if(b-a<=0)
   {
       cout<<"delicious"<<endl;
   }
   else if(b-a<=x)
   {
       cout<<"safe"<<endl;
   }
   else
    cout<<"dangerous"<<endl;

    return 0;
}
