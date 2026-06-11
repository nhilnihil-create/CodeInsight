#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,ans = 0,tmp;
    cin >> N;

    rep(i, N){
        cin >> tmp;
        if(tmp%2 == 1)
            ans++;
    }

    if(ans%2 == 0)
        cout << "YES" << endl;

    else 
        cout <<"NO" << endl;

    return 0;
}