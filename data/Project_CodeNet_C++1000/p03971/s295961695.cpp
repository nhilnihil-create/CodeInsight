#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
    int N, A, B;
    string S;

    cin >> N >> A >> B;
    cin >> S;

    int a_cnt = 0;
    int b_cnt = 0;
    rep(i, N)
    {
        if (A + B <= a_cnt + b_cnt)
        {
            cout << "No" << endl;
        }
        else if (S.at(i) == 'a')
        {
            cout << "Yes" << endl;
            a_cnt++;
        }
        else if (S.at(i) == 'b' && b_cnt < B)
        {
            cout << "Yes" << endl;
            b_cnt++;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}