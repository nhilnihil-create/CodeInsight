#include<bits/stdc++.h>
#include<math.h>
using namespace std;
int main()
{
    long long int n,a,b,x;
    cin>>n>>a>>b;
    if(a==b)
        cout<<"1"<<endl;
    else if(n==1||a>b)
     cout<<"0"<<endl;
     else
     {
         x=(((n-1)*b)+a)-(((n-1)*a)+b);
        cout<<x+1<<endl;
     }
}
