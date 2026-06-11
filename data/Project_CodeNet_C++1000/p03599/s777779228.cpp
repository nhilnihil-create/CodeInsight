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

int closest(int number,int c, int d)
{
    int ans = 0;
    for (int i = 0; d*i <= number; i++)
    {
        int temp = (number-d*i)/c;
        if(number-(temp*c+d*i)<number-ans)
        {
            ans = temp * c + d * i;
        }
    }
 
    return ans;
}

int main()
{
    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    int ans_sugar_water = 100*a;
    int ans_sugar = 0;
    for (int i = 0; 100*a*i <= f; i++)
    {
        for (int j = 0; 100 * b * j + 100 * a * i <= f; j++)
        {
            int remain = f - (100 * b *j + 100 * a *i);
            remain = closest(remain,c,d);
            int dissolvable = (b * j + a * i)*e;
            dissolvable = closest(dissolvable, c, d);
            int sugar = remain>dissolvable ? dissolvable: remain;
            if (sugar * ans_sugar_water > ans_sugar * (100 * b * j + 100 * a * i + sugar))
            {
                ans_sugar_water = sugar + 100 * b * j + 100 * a * i;
                ans_sugar = sugar;
            }
        }
    }
    cout << ans_sugar_water << " " << ans_sugar << endl;
    return 0;
}