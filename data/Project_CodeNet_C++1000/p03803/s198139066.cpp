#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
#define pb push_back
#define eb emplace_back
const  int MAX=1000000;
int main()
{
    ll a,b;

    cin>>a>>b;


    if( (a==1 || a==13 )&& (b==1 || b==13))
    {
             if(a>b)cout<<"Bob"<<endl;
     else if(a<b)cout<<"Alice"<<endl;
 else cout<<"Draw"<<endl;
    }else{
     if(a>b)cout<<"Alice"<<endl;
     else if(a<b)cout<<"Bob"<<endl;
     else cout<<"Draw"<<endl;

    }

}
