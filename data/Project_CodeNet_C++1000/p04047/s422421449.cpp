#include <bits/stdc++.h>
#define NEWLINE '\n'
using namespace std;
typedef long long ll;
///*********************

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n * 2);
    for (auto &it : v)
        cin >> it;
    sort(v.begin(), v.end());
    int sum = 0;
    for (int i = 0; i < n * 2; i += 2)
        sum += v[i];
    cout << sum << NEWLINE;
    return 0;
}
