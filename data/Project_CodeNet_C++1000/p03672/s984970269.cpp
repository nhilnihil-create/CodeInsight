#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    string s;
    cin>>s;
    ll x=s.size();
    if(x&1)s.erase(x-1,1),x-=1;
    else s.erase(x-2,2),x-=2;
    if(s.substr(0,(x/2))==s.substr(x/2,x/2)){cout<<x<<endl;return 0;}
    while(1){
        s.erase(x-2,2),x-=2;
        if(s.substr(0,(x/2))==s.substr(x/2,x/2)){cout<<x<<endl;return 0;}
    }

    return 0;
}
