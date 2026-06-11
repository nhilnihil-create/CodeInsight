#include<bits/stdc++.h>
using namespace std;
using lli = long long;

lli a, b, x;
lli res;

int main(void){
    cin >> a >> b >> x;
    lli c, d;
    c = a/x;
    d = b/x;
    res = d-c;
    if(a%x == 0) res++;
    cout << res << endl;
    return 0;
}
