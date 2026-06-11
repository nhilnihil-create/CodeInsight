/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int S_MAX = 10002;

ll n;

int ans[S_MAX];

int p[S_MAX];

vector <bool> aux;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    n++;
    while(n)
    {
        if(n & 1)
            aux.push_back(1);
        n >>= 1;
        aux.push_back(0);
    }
    aux.pop_back();
    aux.pop_back();
    int r = aux.size(), l = 1;
    int k = aux.size();
    for(bool i : aux)
    {
        if(i == 1)
            p[l++] = k--;
        else
            p[r--] = k--;
    }
    cout << aux.size() * 2 << "\n";
    for(int i = 1; i <= aux.size(); i++)
        cout << p[i] << " ";
    for(int i = 1; i <= aux.size(); i++)
        cout << i << " ";
    cout << "\n";
    return 0;
}
