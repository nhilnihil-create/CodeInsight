#include <bits/stdc++.h>


using namespace std;
using ll= long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const int mod = 1e9 + 7;


int main (){
    int w, a, b;
    cin >> w >> a >> b;
    if (b > a + w){
        cout << b - a - w << endl;
    }
    else if (a > b + w){
        cout << a - b - w << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
}