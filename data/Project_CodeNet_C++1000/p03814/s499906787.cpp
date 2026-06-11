#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;


int main() {
    string s;
    cin >> s;

    int indexA = -1;
    int indexZ = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s.at(i) == 'A' && indexA == -1) indexA = i;
        if (s.at(i) == 'Z') indexZ = i;
    }
    cout << indexZ - indexA + 1 << endl;

}
