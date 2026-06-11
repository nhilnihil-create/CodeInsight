#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define vb vector<bool>
#define pii pair<int,int>
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define F first
#define S second
#define inf (long long) 1e18
#define f(i,n)  for(int i=0;i<n;i++)
#define f(i,n) for(int i=n-1;i>=0;i--)
#define f(i,n) for(int i=1;i<=n;i++)

const int MOD = 1e9 + 7;

void solve()
{
    int n,a,b;
    cin >> n >> a >> b;
    char str[n];
    cin >> str;
    int p=0,bp=0;
    for(int i=0;i<n;i++)
    {
        if(str[i]=='a')
        {
            if(p<a+b)
            {
                p++;
                cout << "Yes" <<"\n";
            }
            else{
                cout << "No" << "\n";
            }
        }
        else if(str[i]=='b')
        {
            if(p<a+b && bp+1<=b){
                p++;bp++;
                cout << "Yes" << "\n";
            }
            else
            {
                cout << "No" << "\n";
            }
        }
        else
            cout << "No" << "\n";
    }
}


int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t=1;
  //cin>>t;
  while(t--)
  {
      solve();
  }
}
