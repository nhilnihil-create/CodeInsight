#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    int N, tmp, free = 0;
    cin >> N;
    map<int, int> list;
    for (int i = 0; i < N; i++)
    {
        cin >> tmp;
        if (tmp >= 3200)
            free++;
        else
            list[tmp / 400]++;
    }
    int size = list.size();
    if (size == 0)
        cout << 1 << ' ';
    else
        cout << list.size() << ' ';
    cout << size + free;
}