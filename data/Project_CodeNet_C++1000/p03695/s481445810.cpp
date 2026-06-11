#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;
template <class T>
using v = vector<T>;
template <class T>
using vv = v<v<T>>;
#define ALL(c) (c).begin(), (c).end()

int main()
{
    int N;
    cin >> N;
    v<int> color(8, 0);
    int free = 0;
    for (int i = 0; i < N; i++)
    {
        int a;
        cin >> a;
        if (a < 3200)
            color[a / 400] = 1;
        else
            free++;
    }

    int min_c = 0, max_c = 0;

    for (int i = 0; i < 8; i++)
    {
        min_c += color[i];
        max_c += color[i];
    }

    min_c = max(1, min_c);
    
    cout << min_c << " " << max_c + free << endl;

    return 0;
}