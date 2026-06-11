#include <bits/stdc++.h>
using namespace std;

int main() {

int n, k;

cin >> n >> k;

int64_t pattern;

pattern = k * pow(k - 1, n - 1);

cout << pattern << endl;

return 0;
}