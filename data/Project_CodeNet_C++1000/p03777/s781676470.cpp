#include <bits/stdc++.h>
#define ll long long int
#define yorn(f) cout<<((f)?"Yes":"No")<<endl
#define YORN(f) cout<<((f)?"YES":"NO")<<endl
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
int main()
{
    string a, b;
    cin >> a >> b;
    if (a == "D") {
        // flip
        b = b == "H" ? "D" : "H"; 
    }
    cout << b << endl;
    return 0;
}