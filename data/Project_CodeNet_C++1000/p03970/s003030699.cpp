#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(), (x).end()

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    // start
    int res = 0;
    char c[16] = {'C',
                  'O',
                  'D',
                  'E',
                  'F',
                  'E',
                  'S',
                  'T',
                  'I',
                  'V',
                  'A',
                  'L',
                  '2',
                  '0',
                  '1',
                  '6'};
    rep(i, 16)
    {
        char s;
        cin >> s;
        if (s != c[i])
            res++;
    }
    cout << res << endl;
    // end

    return 0;
}
