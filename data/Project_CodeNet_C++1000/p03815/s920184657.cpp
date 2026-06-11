#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
#define ll long long
#define rep(i, s, n) for(int i = s; i < n; i++)

int main() {
    ll x;
    cin >> x;
    ll sum = 0;
    int flag = 0;
    ll count = 0;
    ll num = x/11;
    if(x%11 <= 6 && x%11 != 0) {
        flag = 1;
    }
    else if(x%11 != 0) {
        flag = 2;
    }
    cout << num*2+flag << endl;
    
    return 0;
}