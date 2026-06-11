#include <bits/stdc++.h> 
using namespace std; 

int main() {
    string a, b, c; cin >> a >> b >> c;
    int aa = 0, bb = 0, cc = 0; char curr = 'a';
    while(true) {
        if (curr == 'a') {if (aa == a.size()) {cout << "A" << endl; return 0;} curr = a[aa]; aa++; }
        else if (curr == 'b') {if (bb == b.size()) {cout << "B" << endl; return 0;} curr = b[bb]; bb++; }
        else if (curr == 'c') {if (cc == c.size()) {cout << "C" << endl; return 0;} curr = c[cc]; cc++; }
    }
}