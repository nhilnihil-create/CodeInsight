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
    int n;
    cin >> n;
    int a[n+5];
    int tot=0;
    for(int i=0;i<n;i++)
    {
    	int num;
    	cin >> num;
    	a[i]=num;
    	tot=tot+num;
    }
    tot=tot/n;
    int tot2=tot+1;
    int temp=0;
    int temp2=0;
    for(int i=0;i<n;i++)
    {
    	temp=temp+((a[i]-tot)*(a[i]-tot));
    	temp2=temp2+((a[i]-tot2)*(a[i]-tot2));
    }
    cout << min(temp,temp2) << endl;
}
