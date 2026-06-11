#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define ll long long
#define bp  __builtin_popcount
#define pb push_back
#define sz(s) (int)(s.size())

using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag, tree_order_statistics_node_update> indexed_set;
const int maxn=1e6+5;
const  double EPS = 1e-14;
const int MOD = 1e9+7;

ll GCD(ll a,ll b){return (a)?GCD(b%a,a):b;}
ll LCM(ll a, ll b){return a*b/GCD(a,b);}
ll fastpow(ll b, ll p){if(!p)return 1;ll ret = fastpow(b, p >> 1);ret *= ret;if(p&1)ret*= b;return ret;}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
  //  freopen("in.txt", "r", stdin);
#endif
    int n;
    cin>>n;
    int arr[n+5];
    for(int i=0; i<n; i++)
        cin>>arr[i];
    for(int i=1; i<n; i++)
        if(arr[i]==arr[i-1])
        {
            for(int j=i; j<n-1; j++)
                arr[j]=arr[j+1];
            n--;
        }
    int idx=1;
    for(int i=1; i<n-1; i++)
    {
        if(arr[i]>arr[i-1]&&arr[i]>arr[i+1]||arr[i]<arr[i-1]&&arr[i]<arr[i+1])
        {
            idx++;
            arr[i]=arr[i+1];
        }
    }
    cout<<idx;
}
