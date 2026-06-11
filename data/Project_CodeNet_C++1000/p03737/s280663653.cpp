#include <bits/stdc++.h>

using namespace std;
using ll = long long int;
using P = pair<int, int>;

#define roop(i, n) for(int i = 0;i < n;i++)

int main(void){

    string a, b, c;
    cin >> a >> b >> c;

    // int a = 'a';
    // int b = 'A';
    // cout << a << " " << b << endl;
    char d = a[0]-('a'-'A');
    char e = b[0]-('a'-'A');
    char f = c[0]-('a'-'A');

    cout << d << e << f << endl;

    return 0;
}