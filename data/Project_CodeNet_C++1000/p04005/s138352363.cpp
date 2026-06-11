#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 

int main(){
    ull a, b, c;
    cin >> a >> b >> c;
    if(!(a&1) || !(b&1) || !(c&1)){
        cout << 0;
        return 0;
    }
    else{
        cout << min(a*b, min(b*c, a*c));
    }
}
