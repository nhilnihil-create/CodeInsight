#include <bits/stdc++.h>
using namespace std;
const int INF = 2100100100;

int main() {
    string ramen;
    cin >> ramen;
    int len = ramen.size();
    char top = ramen.at(0);
    char last = ramen.at(len-1);
    string length = to_string(len-2);
    string tops = {top};
    string lasts = {last};
    string total = tops + length + lasts;
    cout << total << endl;
    return 0;

}