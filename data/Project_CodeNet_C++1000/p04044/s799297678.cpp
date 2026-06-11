#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    int len;
    cin >> num >> len;
    string words[num];

    for (int i = 0; i < num; i++)
    {
        cin >> words[i];
    }

    for (int i = 0; i < num - 1; i++)
    {
        for (int j = num - 1; j > i; j--)
        {
            string temp;
            if (0 < words[j - 1].compare(words[j]))
            {
                temp = words[j - 1];
                words[j - 1] = words[j];
                words[j] = temp;
            }
        }
    }

    for (int i = 0; i < num; i++)
    {
        cout << words[i];
    }
    cout << endl;
    return 0;
}