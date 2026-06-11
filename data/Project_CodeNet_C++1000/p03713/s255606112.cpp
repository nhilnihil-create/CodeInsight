#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

#define int long long
signed main(){
//int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w;
    cin >> h >> w;

    int dif=INT32_MAX;
    for(int i = 0; i < h; i++) {
        int a=i*w;
        int b=(h-i)*(w/2);
        int c=(h-i)*(w-w/2);
        int mx=max({a,b,c});
        int mn=min({a,b,c});
        dif=min(mx-mn,dif);

        b=((h-i)/2)*w;
        c=((h-i)-(h-i)/2)*w;

        mx=max({a,b,c});
        mn=min({a,b,c});
        dif=min(mx-mn,dif);
    }

    swap(h,w);
    for(int i = 0; i < h; i++) {
        int a=i*w;
        int b=(h-i)*(w/2);
        int c=(h-i)*(w-w/2);
        int mx=max({a,b,c});
        int mn=min({a,b,c});
        dif=min(mx-mn,dif);

        b=((h-i)/2)*w;
        c=((h-i)-(h-i)/2)*w;

        mx=max({a,b,c});
        mn=min({a,b,c});
        dif=min(mx-mn,dif);
    }
    cout << dif << "\n";
    return 0;
}