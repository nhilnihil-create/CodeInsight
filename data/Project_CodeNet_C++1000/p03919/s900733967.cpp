#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int H, W;
    vector<vector<string>> S;
    vector<char> ans1;
    cin >> H >> W;
    for (char i = 'A'; i <= 'Z'; i++)
    {
        ans1.push_back(i);
    }
    for (int i = 0; i < H; i++)
    {
        vector<string> tmp;
        for (int j = 0; j < W; j++)
        {
            string str;
            cin >> str;
            tmp.push_back(str);
        }
        S.push_back(tmp);
    }
    for (int i = 0; i < H; i++)
    {
        for (int j = 0; j < W; j++)
        {
            if (S[i][j] == "snuke")
            {
                cout << ans1[j] << i + 1;
            }
        }
    }

    return 0;
}