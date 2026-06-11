#include<bits/stdc++.h>
#include<cstring>
using namespace std;
#define ll long long



int main()
{
    ll h,w,x=1000000,a,b,c,y,z;
    cin>>h>>w;
    for(int i=1;i<h;i++){
        a=i*w;
        b=floor((h-i)/2.0)*w;
        c=ceil((h-i)/2.0)*w;
        y=max({a,b,c});
        z=min({a,b,c});
        x=min(x,y-z);
        b=floor(w/2.0)*(h-i);
        c=ceil(w/2.0)*(h-i);
        y=max({a,b,c});
        z=min({a,b,c});
        x=min(x,y-z);
    }
    swap(h,w);
    for(int i=1;i<h;i++){
        a=i*w;
        b=floor((h-i)/2.0)*w;
        c=ceil((h-i)/2.0)*w;
        y=max({a,b,c});
        z=min({a,b,c});
        x=min(x,y-z);
        b=floor(w/2.0)*(h-i);
        c=ceil(w/2.0)*(h-i);
        y=max({a,b,c});
        z=min({a,b,c});
        x=min(x,y-z);
    }
    cout<<x<<endl;
}
