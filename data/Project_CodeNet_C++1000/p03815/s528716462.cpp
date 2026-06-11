#include<iostream>
using namespace std;

int main () {
    long long x, ans=0, k;
    cin >> x;

    ans += (x/11)*2;
    k = x%11;

    if (0<k && k<=6) {
        ans += 1;
    }
    else if (6<k){
        ans += 2;
    }

    cout << ans << endl;
    return 0;
}