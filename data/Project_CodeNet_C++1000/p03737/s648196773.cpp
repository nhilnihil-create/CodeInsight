#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

string toUpper(string str) {
    std::transform(str.begin(), str.end(),str.begin(), ::toupper);
    return str;
}

int main()
{
    string a, b, c;
    cin >> a >> b >> c;
    a = toUpper(a);
    b = toUpper(b);
    c = toUpper(c);

    cout << a[0] << b[0] << c[0] << endl;
    return 0;
}