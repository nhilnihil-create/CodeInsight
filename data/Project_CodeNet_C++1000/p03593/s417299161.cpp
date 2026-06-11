#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
    int H, W;
    cin >> H >> W;
    map<char, int> dict;
    char c;
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            cin >> c;
            ++dict[c];
        }
    }

    bool ans = true;
    if (H % 2 == 0 && W % 2 == 0)
    {
        for (auto e : dict)
        {
            if (e.second % 4 != 0)
            {
                ans = false;
            }
        }
    }
    else
    {
        int count = 0;
        for (auto e : dict)
        {
            count += e.second / 4;
        }
        if (count < (W / 2) * (H / 2))
        {
            ans = false;
        }
        else
        {
            count = 0;
            for (auto e : dict)
            {
                if (e.second % 2 != 0)
                {
                    ++count;
                }
            }
            if(H % 2 && W % 2 && count == 1){
                ans = true;
            }
            else if((H%2 == 0 || W%2 == 0) && (count == 0)){
                ans = true;
            }
            else{
                ans = false;
            }
        }
    }
    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
}
