#include <bits/stdc++.h>
using namespace std;
#define ll	    long long
#define vi      vector <int>
#define vii     vector <pair<int,int>>
#define ii      pair<int,int>
#define loop(n)	for(int i=0;i<n;i++)
#define loopj(n)	for(int j=0;j<n;j++)
ll mod=1e9+7;
const int N = 3e6+7, M = 2 * N;
string arr[1009];
int freq[30];
bool prime[N];
int prims[N];
int sz=0;
void SieveOfEratosthenes(ll n)
{
    memset(prime, true, sizeof(prime));
    for (int p=2; p*p<=n; p++)
    {
        if (prime[p] == true)
        {
            prims[sz++]=p;
            for (int i=p*p; i<=n; i += p)
                prime[i] = false;
        }
    }

}
int main()
{
      //freopen ("output.txt","w",stdout);
        //ios_base::sync_with_stdio(0), cin.tie(0),cout.tie(0);
    ll k,w,n;
    cin >> k >>w;
    cout << (k+w)%24 <<endl;
}
