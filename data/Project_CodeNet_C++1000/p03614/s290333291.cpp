#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> PA;
typedef priority_queue<int> PQ;
typedef vector<int> VE;
#define int long long
#define INF 1000000009
#define mod 1000000007
#define pb push_back
#define MAXN 100005

int n, a[100005], res, ans;

signed main()
{
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == i + 1){
            res++;
        }
        else{
            ans += (res + 1) / 2;
            res = 0;
        }
    }
    ans += (res + 1) / 2;
    cout << ans << endl;



    return 0;
}
