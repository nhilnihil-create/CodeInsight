#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
using namespace std;
using ll = long long;

int main() {
    int n;
    cin >> n;
    double k = sqrt(8*n+1)/2.0 - 1.0/2.0;
    int z = int(k);
    if (k != int(k)) ++z;

    for (int i=z;i>0;--i) {
        if (n-i<0) {}
        else if (n-i==0) {
            cout << i << endl;
            break;
        }
        else {
            n -= i;
            cout << i << endl;
        }
    }
    return 0;
}