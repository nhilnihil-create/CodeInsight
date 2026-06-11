#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;

int getgroup(int x)
{
        int gA[7] = {1, 3, 5, 7, 8, 10, 12};
        int gB[4] = {4, 6, 9, 11};
        int gC[1] = {2};

        for (int i = 0; i < 7; ++i) {
                if (x == gA[i]) return 1;
        }
        for (int i = 0; i < 4; ++i) {
                if (x == gB[i]) return 2;
        }
        if (x == gC[0]) return 3;

}

int main()
{
        int x, y;
        cin >> x >> y;
        int xg = 0;
        int yg = 0;
        xg = getgroup(x);
        yg = getgroup(y);
        if (xg == yg) cout << "Yes" << endl;
        else cout << "No" << endl;


}
