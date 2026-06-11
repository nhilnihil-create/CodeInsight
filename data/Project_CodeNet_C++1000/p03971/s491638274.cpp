#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B;
    cin >> N >> A >> B;
    string S;
    cin >> S;

    int tukaninzu = 0;
    int kaigaininzu = 0;

    for (int i = 0; i < N; i++)
    {
        char chr = S[i];
        if (chr == 'a')
        {
            if (tukaninzu < A + B)
            {
                cout << "Yes" << endl;
                tukaninzu++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else if (chr == 'b')
        {
            if (tukaninzu < A + B && kaigaininzu < B)
            {
                cout << "Yes" << endl;
                tukaninzu++;
                kaigaininzu++;
            }
            else
            {
                cout << "No" << endl;
            }
        }
        else
        {
            cout << "No" << endl;
        }
    }
}
