#include <bits/stdc++.h>
#define ll long long
using namespace std;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
	t=1;
    while(t--)
    {
		int a,b,c;
		cin>>a>>b>>c;
		if(b-a==c-b)
			cout<<"YES";
		else
			cout<<"NO";
	}
    return 0;
}