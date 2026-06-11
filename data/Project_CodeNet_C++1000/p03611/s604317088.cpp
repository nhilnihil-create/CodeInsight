#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,tmp = 0,ans = 0;
    map<int,int> mp;
    
    cin >> N;
    
    vector<int> a(N);

    for(int i = -1;i <= 100001;i++)
        mp[i] = 0;

    rep(i, N){
        cin >> tmp;
        mp[tmp]++;
    }


    for(int i = 0;i < 100001;i++){
        tmp = mp[i-1]+mp[i]+mp[i+1];

        ans = max(ans,tmp);
    }
    

    cout << ans << endl;
    

    return 0;
}