#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vll;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    ll w,a,b;
    cin>>w>>a>>b;
    if(a>b)
    {
        swap(a,b);
    }
    if(a+w<b)
        cout<<b-a-w<<endl;
    else
        cout<<0<<endl;
    return 0;
}
