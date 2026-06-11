#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;

int main() {
    string a, b, c;
    cin >> a >> b >> c;
    int na, nb, nc;
    na = a.size();
    nb = b.size();
    if(a[na-1] == b[0] && b[nb-1] == c[0]) {
        cout << "YES" << endl;
    }
    else cout << "NO" << endl;
    return 0;
}
