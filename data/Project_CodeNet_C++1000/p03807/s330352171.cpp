#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int odd = 0;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
        if (a[i] % 2 != 0)
            odd++;
    }

    if (odd % 2 == 0)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}