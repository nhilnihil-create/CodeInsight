//InTheNameOfGod
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define ll long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define rep(i,j,k) for(int i=j;i<k;++i)
#define rrep(i,j,k) for(int i=j;i>=k;i--)
#define pb push_back
#define lb(i) i&(-i);
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn =1e5+5;
int n,a[maxn],ad;
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin>>n;
    rep(i,0,n)
    {
    	cin>>a[i];
    }
    sort(a,a+n);
    while(1)
    {
    	if(a[n-1]-ad==1)
    	{
    		int x=0;
    		while(n&&a[n-1]-ad==1)
    		{
    			x++;
    			n--;
    		}
    		if(x%2==0)cout<<"First";
    		else cout<<"Second";
    		return 0;
    	}
    	if(n==1)
    	{
    		a[0]-=ad;
    		if(a[0]%2==0)cout<<"First";
    		else cout<<"Second";
    		return 0;
    	}
    	if(n>=2&&a[n-2]-ad<=1)
        {
            int x=a[n-1]-ad-1;
            int y=0;
            n--;
            while(n&&a[n-1]-ad==1)
            {
                y++;
                n--;
            }
            if(x%2||y%2)
            {
                cout<<"First";
            }
            else cout<<"Second";
            return 0;
        }
    	n--;
    	ad++;
    }
    return 0;
}
