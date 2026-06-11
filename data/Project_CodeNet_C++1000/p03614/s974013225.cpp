#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    cin >> N;
    int ans = 0;
    bool flag = false;
    for (int i=1; i<=N; i++)
    {
        int tmp;
        cin >> tmp;
        if (flag) flag = false;
        else if (tmp == i)
        {
            ans++;
            flag = true;                
        }
    }
    cout << ans << endl;
    return 0;
}