#include<bits/stdc++.h>

using namespace std;

int main()
{
    long long int n, a, i, cnt;
    set<long long int> s;
    set<long long int>::iterator it;
    cin >> n;
    for(i=0; i<n; i++)
    {
        cin >> a;                    //coded BY Shoaib......
        it= s.find(a);
        if(it== s.end())
        {
            s.insert(a);
        }
        else
        {
            s.erase(a);
        }

    }

    cout << s.size();
    return 0;
}
