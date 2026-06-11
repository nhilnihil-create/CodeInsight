#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

int main() {
    char s[100010];
    cin >> s;

    for (int i = 0; s[i]!='\0'; i++)
    {
        if(i%2==0) cout << s[i];
    }
    cout << endl;
    return 0;
}