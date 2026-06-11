
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int a, b;
bool ok;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> a >> b;
    unordered_set<int> s1 = {1,3,5,7,8,10,12};
    unordered_set<int> s2 = {4,6,9,11};
    unordered_set<int> s3 = {2};
    if (s1.count(a) && s1.count(b))
        ok = true;
    if (s2.count(a) && s2.count(b))
        ok = true;
    if (s3.count(a) && s3.count(b))
        ok = true;
    if (ok)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}

