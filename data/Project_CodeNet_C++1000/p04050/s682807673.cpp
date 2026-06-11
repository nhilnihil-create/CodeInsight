#include <bits/stdc++.h>

using namespace std;

typedef long long int LL;
typedef LL ll;
typedef string str;
typedef pair<ll,ll> pll;
typedef vector<ll> vll;
typedef stringstream strs;

#define X first
#define Y second
#define PB push_back
#define For(i,a,b) for (int i=a;i<b;i++)
#define Ford(i,a,b) for (int i=a;i>=b;i--)
#define smax(a,b) a=max(a,b)
#define smin(a,b) a=min(a,b)
#define SZ(a) ((ll)a.size())
#define ER(a) cout << #a << ' ' << a << endl
#define LB(a,n,x) (lower_bound(a,(a)+(n),x)-(a))

const ll M=3e5+5,LG=26,SM=600,inf=1e9+1;
ll mod=95542721;

ll a[M];
ll n,s;

int main()
{
	ios::sync_with_stdio(0);
    cin >> s >> n;
    if (s==1)
    {
        cout <<"1\n1\n1";
        return 0;
    }
    For(i,0,n) cin >> a[i];
    if (n==1)
    {
        cout << a[0] << "\n2\n" << a[0]-1 << " 1";
        return 0;
    } 
    For(i,1,n-1)
    {
        if (a[i]%2)
        {
            if (a[0]%2)
            {
                if (a[n-1]%2)
                {
                    cout << "Impossible";
                    return 0;
                }
                else
                    swap(a[i],a[n-1]);
            }
            else
                swap(a[i],a[0]);
        }
    }  	
    For(i,0,n)
    {
        cout << a[i] << ' ';
    }
    a[n-1]--;
    a[0]++;
    if (a[n-1]==0)
        n--;
    cout << '\n' << n << '\n';
    For(i,0,n)
    {
        cout << a[i] << ' ';
    }      
}