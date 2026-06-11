#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;

int main(void)
{
    int N,ans = 0;
    bool flag = false;
    cin >> N;
    vector<int> a(N+1);
    vector<bool> d(N+1);

    for(int i = 1;i <= N;i++){
        cin >> a[i];
        d[i] = false;
    }

    for(int i = 1;d[i] == false;i = a[i]){
        d[i] = true;
        ans++;
        if(d[2] == true){
            flag = true;
            break;
        }
    }

    if(flag)
        cout << ans-1 << endl;

    else
        cout << -1 << endl;

    return 0;
}