#include<bits/stdc++.h>
using namespace std;
int main(){
    string a, b, c;
    cin >> a >> b >> c;
    char dif = 'A'-'a';
    string A,B,C;
    A = a[0]+dif;
    B = b[0]+dif;
    C = c[0]+dif;
    cout << A << B << C << endl;
}


