#include <bits/stdc++.h>
using namespace std;

int N;

int main()
{
    cin >> N;

    int cnt = 0;

    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        if (x % 2 == 1)
            cnt++;
    }

    if(cnt%2 == 0){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
