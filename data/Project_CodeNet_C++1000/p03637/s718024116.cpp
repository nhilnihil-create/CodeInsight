#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> P;
#define ll long long
#define ld long double
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define PI 3.14159265358979323846
#define sz(x) ((int)(x).size())
#define chmin(x,y) x = min(x,y)
#define chmax(x,y) x = max(x,y)

const int INF = 1e9;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> counter(3);
    rep(i,3) counter[i] = 0;
    rep(i,n)
    {
        if(a[i]%2==0)
        {
            if (a[i]%4==0)
            {
                counter[2]++;
            }else
            {
                counter[1]++;
            } 
        }else
        {
            counter[0]++;
        } 
    }
    if(counter[1]==0)
    {
        if(counter[2]>=counter[0]-1)
        {
            cout << "Yes" << endl;
            return 0;
        }
        cout << "No" << endl;
        return 0;
    }
    if(counter[2]>=counter[0])
    {
        cout << "Yes" << endl;
        return 0;
    }
    cout << "No" << endl;
    return 0;

}