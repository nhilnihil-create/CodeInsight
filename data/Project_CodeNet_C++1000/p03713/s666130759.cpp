#include <bits/stdc++.h>

using namespace std;

long long int d(long long int x,long long int y){
    long long int a,b,c,w,h,ans=1000000000;
    for(int i=1;i<=y;i++){
        h = (y-i)/2;
        w = x/2;
        a = x*i;
        b = x*h;
        c = x*(y-i-h);
        ans = min(ans,max({a,b,c})-min({a,b,c}));
        b = (y-i)*w;
        c = (y-i)*(x-w);
        ans = min(ans,max({a,b,c})-min({a,b,c}));
    }
    return ans;
}

int main(){
    long long int H,W;
    cin >> H >> W;
    cout << min(d(H,W),d(W,H)) << endl;
}