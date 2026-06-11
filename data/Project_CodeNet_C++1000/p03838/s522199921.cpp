#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x,y; cin>>x>>y;
    long long ans;
    if(abs(x)<abs(y)){
        if(x>=0 && y>0) ans=y-x;
        else if(x*y<=0) ans=abs(y)-abs(x)+1;
        else ans= abs(y)-abs(x)+2;
    }
    else if(abs(x)==abs(y))ans=1;
    else{
        if(x<0 && y<=0) ans=abs(x)-abs(y);
        else if (x*y<=0) ans=abs(x)-abs(y)+1;
        else ans = abs(x)-abs(y)+2;
    }
    cout << ans << endl;
}