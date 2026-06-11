#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x,y;
    cin >> x >> y;
    long long ans;
    if(x==y) ans=0;
    else if(x*y>0&&y>x) ans=abs(abs(x)-abs(y));
    else if(x*y>0&&y<x) ans=abs(abs(x)-abs(y))+2;
    else if(x*y<0&&y>x) ans=abs(abs(x)-abs(y))+1;
    else if(x*y<0&&y<x) ans=abs(abs(x)-abs(y))+1;
    else if(y-x>0&&(x==0||y==0)) ans=abs(abs(x)-abs(y));
    else if(y-x<0&&(x==0||y==0)) ans=abs(abs(x)-abs(y))+1;
    cout << ans << endl;
}