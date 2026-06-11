#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<pair<int, int>> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A.at(i).first;
        A.at(i).second = i;
    }
    sort(A.begin(), A.end());
    int x = 0;
    for (int i = 0; i < N; i++)
    {
        if (A.at(i).second % 2 != i % 2)
        {
            x++;
        }
    }
    cout << x / 2 << endl;
}