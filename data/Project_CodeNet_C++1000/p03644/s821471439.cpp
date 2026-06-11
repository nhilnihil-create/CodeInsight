#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, max = 0, maxNum = 1;
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        int num = i;
        while (num % 2 == 0)
        {
            cnt++;
            num /= 2;
        }
        if (max < cnt)
        {
            max = cnt;
            maxNum = i;
        }
    }
    cout << maxNum << endl;
}