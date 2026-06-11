#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long long INF = 1LL << 60;

int main() {
    string s;
    cin >> s;
    char c_stone = s[0];
    int count = 0;

    for(int i=0; i<s.size()-1; i++) {
        char n_stone = s[i+1];
        if(c_stone != n_stone) {
            c_stone = n_stone;
            count++;
        }
    }
    cout<< count << endl;
}