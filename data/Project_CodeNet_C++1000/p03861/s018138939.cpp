#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    long long a, b, x;
    cin >> a >> b >> x;
    long long ta = a, tb = b;

    if(ta%x != 0) ta += (x - ta%x);
    if(tb%x != 0) tb -= tb%x;
        

    cout << (tb-ta)/x + 1 << endl;;
    return 0;
}