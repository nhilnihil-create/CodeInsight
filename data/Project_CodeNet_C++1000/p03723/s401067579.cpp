#include <bits/stdc++.h>
using namespace std;

static bool is_even(int n)
{
    return n % 2 == 0;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    set<pair<int, int>> list;

    int exchange_count = 0;
    while (is_even(A) && is_even(B) && is_even(C))
    {
        int a = B / 2 + C / 2;
        int b = A / 2 + C / 2;
        int c = A / 2 + B / 2;
        A = a;
        B = b;
        C = c;
        auto p = make_pair(a, b);
        if (list.find(p) != list.end())
        {
            exchange_count = -1;
            break;
        }
        list.insert(move(p));
        exchange_count++;
    }

    cout << exchange_count << endl;

    return 0;
}
