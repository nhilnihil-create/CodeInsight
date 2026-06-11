#include<bits/stdc++.h>
#define rep(i, n) for (int i=0; i < n; i++)
#define repd(i, n) for (int i = n-1; i > -1; i--)
#define all(x) (x).begin(), (x).end()
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        int s;
        cin >> s; s--;
        a[i] = s;
    }
    vector<bool> visited(n);
    rep(i, n) visited[i] = false;
    
    int num = 0, cnt = 0;
    bool flag = false;
    while(true){
        if (visited[num]) break;
        if (num == 1) {
            flag = true;
            break;
        }
        visited[num] = true;
        num = a[num];
        cnt++;
    }
    if (flag) {
        cout << cnt << endl;

    } else {
        cout << -1 << endl;
    }


}