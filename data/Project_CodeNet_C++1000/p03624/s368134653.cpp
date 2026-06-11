#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S, atoz;
    int sum = 0;
    cin >> S;
    atoz = "abcdefghijklmnopqrstuvwxyz";
    vector<bool> A(27);

    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; j < atoz.size(); j++)
        {
            if (S.at(i) == atoz.at(j) && A.at(j) == false)
            {
                A.at(j) = true;
                sum++;
            }
        }
    }

    for (int i = 0;;i++)
    {
        if(A.at(i)==false)
        {
            cout << atoz.at(i) << endl;
            break;
        }else if(sum>=26)
        {
            cout << "None" << endl;
            break;
        }
    }
}
