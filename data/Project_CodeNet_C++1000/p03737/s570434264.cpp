#include <bits/stdc++.h>
using namespace std;

int main(){
    string A, B, C;
    cin >> A >> B >> C;

    char a = A.at(0);
    char b = B.at(0);
    char c = C.at(0);

    int d = (int)a - 32;
    int e = (int)b - 32;
    int f = (int)c - 32;

    cout << (char)d << (char)e << (char)f << endl;
}