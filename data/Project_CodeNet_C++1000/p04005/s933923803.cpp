#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    long long a,b,c,d;
    cin >>a >>b >>c;
    if(a%2==0||b%2==0||c%2==0){
        cout << 0;return 0;
    }
    d =a*b;b*=c;c*=a;
    cout << min(min(d,b),min(b,c));
}


