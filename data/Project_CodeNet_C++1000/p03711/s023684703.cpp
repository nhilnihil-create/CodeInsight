#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define INF 1999999999
#define MODA 1000000007

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int x, y;
    cin >> x >> y;
    vector<int> group1 = {1, 3, 5, 7, 8, 10, 12};
    vector<int> group2 = {4, 6, 9, 11};
   
    int count1 = 0;
    for(int i = 0; i < group1.size(); i++)
    {
        if(group1[i] == x || group1[i] == y)
        {
            count1++;
        }
    }

    int count2 = 0;
    for(int i = 0; i < group2.size(); i++)
    {
        if(group2[i] == x || group2[i] == y)
        {
            count2++;
        }
    }

    if(count1 == 2 || count2 == 2)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    return 0;
}
