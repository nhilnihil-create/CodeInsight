#include <bits/stdc++.h>
 
typedef long long ll;
#define SIZE_OF_ARRAY(array) (sizeof(array)/sizeof(array[0]))
#define rep(i, n) for (int i = 0; i < (n); ++i)
const double PI=3.14159265358979323846;

using namespace std;

int main() {

    string s;

    cin >> s;

    int i = s.length() / 2;
    if (s.length() % 2 != 0) i++;

    string ans = "";

    for (int j = 0; j < i; j++) {
        ans += s[j*2];
    }

    cout << ans << endl;
}