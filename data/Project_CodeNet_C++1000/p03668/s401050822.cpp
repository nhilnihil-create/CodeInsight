#include <bits/stdc++.h>
using namespace std;

vector <int> adia[100010];

int calc(int nod, int tata)
{
    int ans = 0;
    vector <int> fii;
    for (auto i : adia[nod]) {
        if (i == tata)
            continue;
        int x = calc(i, nod);
        ans ^= (x + 1);
    }

    return ans;
/*
    if (fii.size() == 0)
        return 0;
    sort(fii.begin(), fii.end());

    int mex = 0;
    for (auto i : fii) {
        if (i == mex)
            mex++;
        else if (i > mex)
            return mex;
    }
    return mex;*/
}

int main()
{
    int n, a, b;
    cin >> n;

    while (--n) {
        cin >> a >> b;
        adia[a].push_back(b);
        adia[b].push_back(a);
    }

    cout << (calc(1, 0) ? "Alice" : "Bob");
    return 0;
}
