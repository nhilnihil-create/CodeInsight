#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define ll long long


int main(){
    int a, b, c;
    cin >> a  >> b >> c;
    int ans=0;

    while(!(a&1) && !(b&1) && !(c&1)){
        if(a==b && b==c){
            cout << -1;
            return 0;
        }


        int sa = a/2;
        int sb = b/2;
        int sc = c/2;

        a = sb + sc;
        b = sa + sc;
        c = sb + sa;
        ans++;
    }

    cout << ans;
    return 0;
}