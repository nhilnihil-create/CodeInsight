#include <bits/stdc++.h>
using namespace std;

int main(){
    string A, B, C;
    cin >> A >> B >> C;

    int a = (int)A.at(0) - 32;
    int b = (int)B.at(0) - 32;
    int c = (int)C.at(0) - 32;

    cout << (char)a << (char)b << (char)c << endl;
}