#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define pb push_back
#define vi vector<int>
#define vll vector<long long>
#define inf 1000000100
#define infll 1LL << 50

int main()
{
    int n;
    cin >> n;
    int g = 0;
    set<int> colors;
    while(n--)
    {
        int a;
        cin >> a;
        if(a < 3200)
        {
            colors.insert(a/400);
        }
        else
        {
            g++;
        }
    }

    cout << max(1, (int)colors.size()) << " " << colors.size() + g << endl;

}
