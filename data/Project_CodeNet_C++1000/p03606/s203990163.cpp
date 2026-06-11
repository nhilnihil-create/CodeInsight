#include <iostream>
#include <vector>
#include <string>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
int main()
{
    int n;
    cin >> n;
    int sum = 0;

    vector<int> l(n), r(n);
    rep(i, n)
    {
        cin >> l[i] >> r[i];
        sum += (r[i] - l[i]) + 1;
    }
    cout << sum << endl;
    return 0;
}
