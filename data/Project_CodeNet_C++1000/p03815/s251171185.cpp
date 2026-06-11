#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    long long ans;
    if(n%11==0)ans=(n/11)*2;
    else if(n%11>0&&n%11<=6) ans=(n/11)*2+1;
    else ans=(n/11)*2+2;
    cout << ans << endl;
}