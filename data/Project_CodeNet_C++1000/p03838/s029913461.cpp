#include <bits/stdc++.h>
using namespace std;

int main(){
    long long x,y;
    cin >> x >> y;
    long long ans=LLONG_MAX;

    //反転0
    if(x<=y) ans=min(ans,y-x);
    //最初に反転しておわり
    if(-x<=y) ans=min(ans,1+y-(-x));
    //2回とも反転
    if(-x<=-y) ans=min(ans,2+(-y)-(-x));
    //最後だけ反転
    if(x<=-y) ans=min(ans,1+(-y)-x);

    cout << ans << endl;
    return 0;
}