#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, k;

    cin >> n >> k;

    ///string money = to_str(n);
    deque<int> no(k);

    for(int i = 0; i < k; i++)
    {
        cin >> no[i];
    }

    for(int i = n; ; i++)
    {
        int temp = i;

        bool found = true;

        while(temp > 0)
        {
            int d = temp % 10;
            temp /= 10;

            for(int var : no)
            {
                if(d == var)
                {
                    found = false;
                    temp = 0;

                    break;
                }
            }
        }

        if(found == true)
        {
            cout << i << endl;

            break;
        }
    }

    return 0;
}

