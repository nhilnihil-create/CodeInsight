#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007
#define PI 3.1415926535897932384626433

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    int len = s.length();
    //cout << len << endl;
    int lenS = len - 2;
    cout << s[0] << lenS << s[len-1] << endl;

    return 0;
}
