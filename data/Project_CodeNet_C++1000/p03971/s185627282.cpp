#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, A, B, line;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    line = A + B;
    int pass = 0;
    int foreigner = 0;

    for (int i = 0; i < N; i++)
    {
        char tmp;
        tmp = S[i];
        bool flg = false;

        switch (tmp)
        {
        case 'a':
            if (pass < line)
            {
                flg = true;
                pass++;
            }
            break;
        case 'b':
            if (pass < line && foreigner < B)
            {
                flg = true;
                pass++;
                foreigner++;
            }
            break;
        default:
            break;
        }

        if (flg)
        {
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }
}
