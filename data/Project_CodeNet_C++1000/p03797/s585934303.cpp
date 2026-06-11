#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll s,c;
    cin >> s >> c;
    if(2*s>=c) cout << c/2<< endl;
    else cout << s+ (c-s*2)/4 << endl;
}