#include <iostream>
using namespace std;

int main() {
    string stra,strb,strc;
    cin >> stra >> strb >> strc;
    int xa,xb,xc,ya,yb,yc;
    char a = stra[0];
    char b = strb[0];
    char c = strc[0];
    xa = (int)a;
    xb = (int)b;
    xc = (int)c;
    ya = xa-32;
    yb = xb-32;
    yc = xc-32;
    cout << (char)ya << (char)yb << (char)yc << endl;
}