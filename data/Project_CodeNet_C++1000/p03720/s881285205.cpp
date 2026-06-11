#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 1; i <= (n); i++)
typedef long long ll;

int main(void)
{
    int N,M;
    int tmp;
    cin >> N >> M;
    map<int,int> mp;

    rep(i, N){
        mp[i] = 0;
    }
    rep(i,M){
        cin >> tmp;
        mp[tmp]++;
        cin >> tmp;
        mp[tmp]++;
    }

    rep(i,N){
        cout << mp[i] << endl;
    }

    return 0;
}