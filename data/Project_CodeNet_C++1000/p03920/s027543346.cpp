#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000


int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    if ( N == 1 ) {
        cout << "1" << endl;
        return 0;
    }
    int cnt = 1;
    int sum = 0;
    while (N > sum) {
        sum += cnt;
        cnt++;
        //dump(sum);
    }
    int tmp = 1;
    while (cnt > 1) {
        if (tmp != sum - N) {
            cout << tmp << endl;
        }
        cnt--;
        tmp++;
    }

    

    return 0;
}
