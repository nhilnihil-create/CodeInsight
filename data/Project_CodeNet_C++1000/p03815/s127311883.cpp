#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll x;

int main(){
    cin >> x;
    ll Now = x / 11;
    Now <<= 1;
    ll Yu = x % 11;
    if(Yu > 6) Now += 2;
    else if( Yu > 0) Now += 1;
    cout << Now <<endl;
    return 0;
}

