#include <iostream>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    int cnt[26] = {};
    for (int i = 0; i < H; i++)
    {
        string s;
        cin >> s;
        for (auto c : s)
        {
            cnt[c - 'a']++;
        }
    }

    int g4 = (H / 2) * (W / 2);
    int g2 = (H / 2) * (W & 1) + (W / 2) * (H & 1);
    int g1 = H & W & 1;
    int groups[] = {g4, g2, g1};
    int subs[] = {4, 2, 1};
    for (int g = 0; g < 3; g++)
    {
        for (int i = 0; i < groups[g]; i++)
        {
            bool ok = false;
            for (int j = 0; j < 26; j++)
            {
                if (cnt[j] >= subs[g])
                {
                    cnt[j] -= subs[g];
                    ok = true;
                    break;
                }
            }
            if (!ok)
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
}