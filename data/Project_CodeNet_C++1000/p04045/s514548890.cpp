#include<bits/stdc++.h>

using namespace std;

bool IsContainInvalidDigits(int n, vector<int > d)
{
    while(n)
    {
        int curr = n % 10;
        for(auto it: d)
        {
            if(it == curr)
                return true;
        }

        n /= 10;      
    }

    return false;
}

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int > a(k);
    for(auto &it: a)
        cin >> it;

    int res = n;
    while(IsContainInvalidDigits(n, a))
    {
        res = ++n;
    }

    cout << res;
    return 0;
}