#include <bits/stdc++.h>
#include <queue>
#define REP(i, n) for (ll i = 1; i <= n; i++)
#define rep(i, n) for (ll i = 0; i < n; i++)
#define ll long long
#define ld long double
using namespace std;

ll Sum = 0;
string S;

ll addByString(string keep_S)
{

    string k = keep_S;
    ll sum = 0;
    ll count = 0;
    rep(i, keep_S.size())
    {
        if (keep_S.at(i) == '+')
        {
            sum += stoll(k.erase(i - count)); //+より前を取得
            // cout << "erase:" << k << endl;
            count += k.size() + 1; //取得した部分のサイズぶんたす
            k = keep_S;            //kをもとにもどす
            k = k.substr(count);   //取得した部分をのぞく
            // cout << "substr:" << k << endl;
        }
        if (i == keep_S.size() - 1)
        {
            sum += stoll(k);
        }
    }
    return sum;
}

ll Calc(string S, string c, int Size_S)
{
    ll sum = 0;
    int count = 0;
    int cutSize = c.size();
    string Cut_first = c;
    string keep_S = S;

    //cout << "cut:" << c << endl;

    vector<int> keep(0);
    //cut = 1 0 1 1 //S = 1 2 3 4 5
    rep(i, cutSize)
    {
        if (c.at(i) == '1')
        {

            if (i + 1 + count < keep_S.size())
            {
                keep_S.insert(i + 1 + count, "+");
            }
            count++;
        }
    }
    sum = addByString(keep_S);
    //cout << keep_S << endl;

    return sum;
}

int main()
{

    //1〇2〇5   2^(n-1) max 512通り
    cin >> S;
    int Size_S = S.size();

    for (int tmp = 0; tmp < (1 << (Size_S - 1)); tmp++)
    {
        bitset<9> bs(tmp); //整数tmpを9個のbit列で表す
        string cut = bs.to_string().substr(10 - Size_S);
        //cout << bs << endl;
        Sum += Calc(S, cut, Size_S);
    }
    cout << Sum << endl;
}
