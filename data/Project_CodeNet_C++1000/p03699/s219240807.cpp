#include<bits/stdc++.h>
#define ll long long
#define MAX 1000005
#define MOD (ll)(1e9+7)
using namespace std;

void solve()	{
    int n;
    cin >> n;
    int a[n],s=0;
    for(int i=0; i<n; i++)  {
        cin >> a[i];
        s+=a[i];
    }
    if(s%10)    cout << s << endl;
    else {
        sort(a,a+n);
        for(int i=0; i<n; i++)  {
            if(a[i]%10) {
                cout << s-a[i] << endl;
                return;
            }
        }
        cout << 0 << endl;
    }

}

int main()	
{
	int t=1;
	//cin >> t;
	for(int i=1; i<=t; i++)	{
		solve();
	}
	return 0;
}