#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     #ifndef ONLINE_JUDGE
 
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
 
   #endif
   long long int a,b;
   char c;
   cin>>a>>c>>b;
   if(c=='+')
    cout<<a+b;
else
    cout<<a-b;
   
    return 0;
}






