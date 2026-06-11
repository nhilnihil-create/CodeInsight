 #include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    string sr = s;
    reverse(sr.begin(), sr.end());
    if(sr == s)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }

    return 0;
}
