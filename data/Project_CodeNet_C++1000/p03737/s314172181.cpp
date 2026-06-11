#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()


int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    char dif = 'A' - 'a';
    printf("%c%c%c",s1[0] + dif, s2[0] + dif, s3[0] + dif);
    cout << endl;
}
