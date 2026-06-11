#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

const int N = 105;
int a[N];

ll sum(string s)
{
    ll sum = 0, temp = 0;
    for(int i = 0; i < s.size(); i++)
    {
        if(s[i] == '+')
        {
            sum += temp;
            temp = 0;
        }
        else
            temp = temp * 10 + s[i] - '0';
    }
    return sum + temp;
}

int main()
{
    string s;
    cin >> s;

    ll res = 0;

    while(1)
    {
        string temp;

        for(int i = 0; i < s.size() - 1; i++)
        {
            a[i + 1] += a[i] / 2;
            a[i] %= 2;
        }

        if(a[s.size() - 1])
            break;

        for(int i = 0; i < s.size() - 1; i++)
        {
            temp += s[i];

            if(a[i])
                temp += "+";
        }

        temp += s[s.size() - 1];

        res += sum(temp);
        a[0]++;
    }

    cout << res << '\n';

    return 0;
}
