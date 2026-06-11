#include <iostream>
#include <vector>
#include <algorithm>

#define rep(i, n) for(int i=0; i<(int) n; i++)

using namespace std;
typedef long long ll;

int main() {
    string s;
    cin >> s;

    if (s.find("YAKI") == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}