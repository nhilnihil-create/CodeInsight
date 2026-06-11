#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
#define _ << ' ' <<
using namespace std;
using ll = long long;

const string z[4] = {"WW", "SW", "WS", "SS" };
string sol;
map<char, char> inv = {{'W', 'S'}, {'S', 'W'}};

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    sol.resize(n);
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 2; ++j)
            sol[j] = z[i][j];

        for (int k = 1; k <= n; ++k)
        {
            if (s[k%n] == 'o')
                sol[(k+1)%n] = (sol[k%n] == 'S' ? sol[(k-1+n)%n] : inv[sol[k-1]]);
            else
                sol[(k+1)%n] = (sol[k%n] == 'S' ? inv[sol[(k-1+n)%n]] : sol[k-1]);
        }
        if (sol[0] == z[i][0] && sol[1] == z[i][1])
            return cout << sol, 0;
    }
    cout << -1;
}
