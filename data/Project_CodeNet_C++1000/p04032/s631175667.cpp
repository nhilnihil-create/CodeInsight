#include <bits/stdc++.h>
using namespace std;
#define INF 100005
#define MOD 1000000007

int main()
{
	//freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    string a;
    cin >> a;
    int n=a.size();
    for(int i=0;i<n-1;i++)
    {
    	if(a[i]==a[i+1])
    	{
    		cout << i+1 << " " << i+2 << endl;
    		return 0;
    	}
    }
    for(int i=0;i<n-2;i++)
    {
    	if(a[i]==a[i+2])
    	{
    		cout << i+1 << " " << i+3 << endl;
    		return 0;
    	}
    }
    cout << -1 << " " << -1 << endl;
}
