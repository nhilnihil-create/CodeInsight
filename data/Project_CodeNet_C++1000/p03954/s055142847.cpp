#include<bits/stdc++.h>

using namespace std;

const int MAX_N = 5 * (int) 1e5;
int n;
int v[MAX_N];

bool check(int x)
{
    int middle = n - 1;
    int range = 1;

    while (range <= n - 1 && ((v[middle - range] >= x) == (v[middle + range] >= x)) && ((v[middle - range] >= x) != (v[middle - range + 1] >= x)))
        range++;

    return v[middle - range + 1] >= x;
}

int binsearch(int left, int right)
{
    if (left == right)
        return left;
    if (left == right - 1)
    {
        if (check(right))
            return right;
        else
            return left;
    }

    int middle = (left + right) / 2;

    if (check(middle))
        return binsearch(middle, right);
    else
        return binsearch(left, middle - 1);
}

int main()
{
    scanf("%d", &n);
    int s = 2 * n - 1;

    for(int i = 0; i < s; i++)
    {
        scanf("%d", &v[i]);
    }

    int _min = v[0], _max = v[0];
    for(int i = 1; i < s; i++)
    {
        _min = min(_min, v[i]);
        _max = max(_max, v[i]);
    }
    printf("%d", binsearch(_min, _max));

    return 0;
}
