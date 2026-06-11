// C - Be Together
#include<bits/stdc++.h>
#define fast ios::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
#define int long long
#define MOD 1000000007
typedef vector<int> vi;
typedef pair<int,int> pi;
#define inf INT_MAX
#define For(i,a,b) for (int i = a; i < b; i++)
#define Rep(i,a,b) for (int i = a; i <= b; i++)
#define ps(x,y) fixed << setprecision(y) << x 
#define pb push_back 
#define mp make_pair 

int a[105];
 
int32_t main()
{
    fast;
    int n, ans1 = 0, ans2 = 0, avg = 0; cin >> n;
    For(i, 0, n) {
        cin >> a[i];
        avg += a[i];
    }
    avg /= n;
    For(i, 0, n) {
        ans1 += (a[i] - avg) * (a[i] - avg);
        ans2 += (a[i] - avg - 1) * (a[i] - avg - 1);
    }

    cout << min(ans1, ans2);

    
    return 0;
}