#include <bits/stdc++.h>
using namespace std;

// 
// 以下はアウトになるコード
// 

int N;
map<int,int> mp;

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        mp[x]++;
    }

    int cnt = 0;

    for(auto itr = mp.begin(); itr != mp.end(); ++itr) {
        if(itr->second%2 == 1) cnt++;
    }

    cout << cnt << endl;

    return 0;
}
