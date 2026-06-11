#include <iostream>

using namespace std;
int main()
{
    int N;
    cin >> N;

    int ans = N;
    int cnt = 0;
    int max = 0;
    for (int i = 0; i <= N; i++)
    {
        int tmp = i;
        while (true)
        {
            if (tmp % 2 == 0 && tmp != 0)
            {
                cnt++;
                if (cnt > max)
                {
                    ans = i;
                    max = cnt;
                }
                tmp /= 2;
            }
            else
            {
                break;
            }
        }
        cnt = 0;
    }

    cout << ans;
}