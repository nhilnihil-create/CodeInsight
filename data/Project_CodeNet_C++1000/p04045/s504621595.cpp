#include<bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
using namespace std;
typedef long long ll;
bool isvalid(bool valid[],int n)
{
    bool ok=true;
    while(n>0)
    {
        if(!valid[n%10]) ok=false;
        n/=10;
    }
    return ok;
}
int main(){
   #ifndef ONLINE_JUDGE 
      FILE_READ_IN 
      FILE_READ_OUT 
   #endif
   int n; cin>>n;
   int d; cin>>d;
   bool valid[10];
 
   fill(valid,valid+10,true);
   for(int i=0;i<d;i++)
   {
       int x; cin>>x;
       valid[x]=false;
   }
   int i=n;
   while (i<=10*n&&!isvalid(valid,i))
   {
       i++;
   }
   cout<<i<<"\n";
   
   return 0;
}