#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 1000000000000000018
#define mod 1000000007
typedef priority_queue<int> PQ;
typedef priority_queue<int, vector<int>, greater<int> > PQG;

PQ qr;
PQG ql;
int n, a[300005], suml, sumr, kl[100005], kr[100005], ans = -INF;

signed main()
{
    cin >> n;
    for(int i = 0; i < 3 * n; i++){
        cin >> a[i];
        if(i < n){
            ql.push(a[i]);
            suml += a[i];
        }
        else if(i >= 2 * n){
            qr.push(a[i]);
            sumr += a[i];
        }
    }
    kl[0] = suml;
    for(int i = n; i < 2 * n; i++){
        ql.push(a[i]);
        suml += a[i];
        suml -= ql.top();
        ql.pop();
        kl[i - n + 1] = suml;
    }
    kr[n] = sumr;
    for(int i = 2 * n - 1; i >= n; i--){
        qr.push(a[i]);
        sumr += a[i];
        sumr -= qr.top();
        qr.pop();
        kr[i - n] = sumr;
    }
    for(int i = 0; i <= n; i++){
        ans = max(ans, kl[i] - kr[i]);
    }
    cout << ans << endl;



    return 0;
}
