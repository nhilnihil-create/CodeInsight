#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    //入力処理
    string S;
    cin >> S;
    vector<string> inputs = { //inputsという配列に4つの要素がある
        "dream",
        "dreamer",
        "erase",
        "eraser"
    };
    reverse(S.begin(), S.end());//文字列sを反転している
    for (int i = 0; i < inputs.size(); i++)//配列内すべての要素を反転している
        reverse(inputs[i].begin(), inputs[i].end());
    //入力　反転処理終了

    int pos = 0;
    while (true)//trueの間ループし続ける
    {
        bool update = false;
        for (int i = 0; i < inputs.size(); i++)//inputsのサイズ(4)回ループする
        {
            if (S.substr(pos, inputs[i].size()) == inputs[i])//もしsの0から
            {
                update = true;
                pos += inputs[i].size();
                break;
            }
        }
        if (!update)
            break;
    }

    if (pos == S.size())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
}
