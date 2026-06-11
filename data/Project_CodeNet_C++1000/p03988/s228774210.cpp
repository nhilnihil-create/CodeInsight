#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main()
{
    int n;
    cin >> n;
    multiset<int> ms;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        ms.insert(a);
    }

    int l = *ms.begin();
    if(ms.count(l) > 2)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    if(l == 1)
    {
        if(ms.count(1)==2 && n == 2)
        {
            cout << "Possible" << endl;
            return 0;
        }
        if(ms.count(l) == 1 && ms.count(2) == n-1)
        {
            cout << "Possible" << endl;
        }
        else
        {
            cout << "Impossible" << endl;
        }
        return 0;
    }

    int r = *ms.rbegin();
    if(r > l * 2 || r >= n)
    {
        cout << "Impossible" << endl;
    }
    else if(r % 2 == 0 && ms.count(l) == 2)
    {
        cout << "Impossible" << endl;
    }
    else
    {
        auto itr = ms.begin();
        int now = *itr;
        int s = ms.count(*itr);
        int nowc = s;
        while(s) //count(*itr) = 1 is ok
        {
            itr++;
            s--;
        }
        int next = *itr;
        int nextc = ms.count(next);
        while(itr != ms.end())
        {
            if(ms.count(*itr) < 2 || next != now+1)
            {
                cout << "Impossible" << endl;
                return 0;
            }
            int size = ms.count(*itr);
            while(size)
            {
                itr++;
                size--;
            }
            now = next;
            next = *itr;
            nowc = nextc;
            nextc = ms.count(next);
        }
        cout << "Possible" << endl;
    }
}