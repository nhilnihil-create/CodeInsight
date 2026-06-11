#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define MAX_N 25
using namespace std;

int vec[MAX_N];
int n, k;
long int sum = 0;
string s;

int main()
{
    cin >> s;
    // reverse(s.begin(), s.end());
    for (int i = 0; i < s.length(); i++)
    {
        vec[i] = s[i] - '0';
    }

    for (int bit = 0; bit < (1 << s.length() - 1); ++bit)
    {
        int anc = 0;
        for (int i = 0; i < s.length() - 1; ++i)
        {
            if (bit & (1 << i))
            {
                sum += stol(s.substr(anc, i + 1 - anc));
                anc = i + 1;
            }
        }
        sum += stol(s.substr(anc, s.length() - anc));
    }

    cout << sum << endl;
}