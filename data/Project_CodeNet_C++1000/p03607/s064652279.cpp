#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,ans = 0,tmp;
    cin >> N;
    map<int,int> mp;

    rep(i,N){
        cin >> tmp;
        mp[tmp]++;
    }

    

    for(auto i:mp){
        if(i.second%2 == 1) ans++;
    }

    cout << ans << endl;
    
    return 0;
}