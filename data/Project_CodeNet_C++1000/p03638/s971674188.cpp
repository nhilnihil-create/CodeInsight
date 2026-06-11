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
    int hgt,w;cin >>hgt >> w;
    int n;cin >> n;
    vector<int> a(n);rep(i,n)cin >> a[i];
    vector<vector<int> > c(hgt, vector<int>(w));
    int h,l;h = 0;l = 0;
    int flag = 0;
    int color = 0;
    while(color < n)
    {
        rep(j,a[color])
        {
            if(flag == 0)
            {
                if(l>=w)
                {
                    h++;
                    flag++;
                    l = w-1;
                    c[h][l] = (color+1);
                    l--;
                    continue;
                }
                c[h][l] = (color+1);
                l++;
            }else
            {
                if(l<0)
                {
                    h++;
                    flag  = (flag+1)%2;
                    l=0;
                    c[h][l] = (color+1);
                    l++;
                    continue;
                }
                c[h][l] = (color+1);
                l--;
            }
            
        }
        color++;
    }
    rep(i,hgt)
    {
        rep(j,w)
        {
            cout << c[i][j] << " ";
        }
        cout  << endl;
    }
}