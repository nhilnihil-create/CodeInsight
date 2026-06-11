#include <iostream>
#include<vector>

using namespace std;

int main() {
    int a, b, c, index = 1;
    cin >> a >> b >> c;
    vector<bool> df(b-1);

    while (true) {
        int amari = a * index % b;
        //cout << amari << ", " << (bool)df[amari] << endl;
        if (amari == c) {
            cout << "YES" << endl;
            return 0;
        } else if (df[amari]) {
            cout << "NO" << endl;
            return 0;
        } else {
            df[amari] = true;
            index++;
        }
    }
}