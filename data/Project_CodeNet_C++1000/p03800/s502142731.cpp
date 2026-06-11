#include <algorithm>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

using namespace std;
using LLONG = long long;
const LLONG MOD = 1000000007;

int main()
{
    int N; cin >> N;
    string s; cin >> s;
    vector<int> S(N);
    for (int i = 0; i < N; ++i)
    {
        S[i] = s[i] == 'o' ? 1 : -1;
    }
    // Ai は i 番目の動物が羊のとき +1, 狼のとき -1 をとるとし，
    // Si は si = o のとき +1, si = x のとき -1 をとるとすると
    // A{i-1} * A{i+1} = Ai * Si が成立する
    // A0, A1 を決めれば残りは順に計算できる -> 矛盾がでなければOK
    vector<int> ansAs;
    bool hasFound = false;
    for (const int A0 : {1, -1})
    {
        for (const int A1 : {1, -1})
        {
            vector<int> tmpAs(N);
            tmpAs[0] = A0, tmpAs[1] = A1;
            for (int i = 0; i < N; ++i)
            {
                tmpAs[(i + 2) % N] = tmpAs[(i + 1) % N] * S[(i + 1) % N] / tmpAs[i];
            }
            if (tmpAs[0] == A0 && tmpAs[1] == A1)
            {
                hasFound = true;
                ansAs = tmpAs;
                break;
            }
        }
        if (hasFound) break;
    }
    if (hasFound)
    {
        for (const int Ai : ansAs)
        {
            cout << (Ai == 1 ? 'S' : 'W');
        }
        cout << endl;
    }
    else
    {
        cout << -1 << endl;
    }
}
