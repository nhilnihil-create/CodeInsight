#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int i = 1;
    int cand = 1;
    for(; i <= 10; i++)
    {
        cand *= 10;
        cout << "? " << cand << endl;
        char ans;
        cin >> ans;
        if(ans == 'N') break;
    }

    if(i == 11)
    {
        // n : 10の階乗のとき
        cand = 1;
        for(int j = 0; j < 10; j++)
        {
            cand *= 10;
            cout << "? " << cand-1 << endl;
            char ans;
            cin >> ans;
            if(ans == 'Y')
            {
                cout << "! " << cand/10 << endl;
                return 0;
            }
        }
    }
    else
    {
        // i:桁数
        int num = 0;
        for(int k = 1; k <= i; k++)
        {
            int cand = 0;
            int d[4] = {8, 4, 2, 1};
            for(int j = 0; j < 4; j++)
            {
                if(cand + d[j] > 9) continue;
                cand += d[j];
                ll query = cand * 1e9 + num * pow(10, 10-(i-k+1));
                query = query / pow(10, k-1) -1;
                cout << "? " << query << endl;
                char ans;
                cin >> ans;
                if(ans == 'Y')
                {
                    cand -= d[j];
                }
            }
            if(k==1 && cand == 0) cand = 1;
            num += cand * pow(10, i-k);
        }
        cout << "! " << num << endl;
        return 0;
    }
}