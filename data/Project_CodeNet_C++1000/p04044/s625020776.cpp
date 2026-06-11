#include <bits/stdc++.h>
using namespace std;

//文字列も数値として扱える話
int main()
{
    int N, L;
    cin >> N >> L;

    vector<string> S(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> S[i];
    }
    sort(S.begin(), S.end());
    for (auto &&i : S)
    {
        cout << i;
    }
    cout << endl;
}
