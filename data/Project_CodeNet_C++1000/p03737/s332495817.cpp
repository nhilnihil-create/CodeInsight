#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b,c;
    cin >> a >> b >> c;
    int x = 'A'-'a';
    cout << char(a[0]+x) << char(b[0]+x) << char(c[0]+x) << endl;
    return 0;
}
