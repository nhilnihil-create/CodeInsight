#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    int e, f;

    e = a * b;
    f = c * d;

    if (e >= f){
        cout << e << endl;
    } else {
        cout << f << endl;
    }
}