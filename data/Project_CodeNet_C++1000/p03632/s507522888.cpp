#include<bits/stdc++.h>
#define ll long long int
using namespace std;



int main()
{
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    if(c>=a&&d<=b)cout<<d-c;
    else if(a>=c&&b<=d)cout<<b-a;
    else if(a>=c&&b>=d&&a<=d)cout<<d-a;
    else if(c>=a&&d>=b&&c<=b)cout<<b-c;
    else if(c<=a&&d<=b&&d>=a)cout<<d-a;
    else if(a<=c&&b<=d&&b>=c)cout<<b-c;
    else cout<<0;

    return 0;
}
