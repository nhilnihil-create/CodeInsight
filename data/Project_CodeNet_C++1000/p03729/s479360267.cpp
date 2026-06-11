#include<bits/stdc++.h>
using namespace std;
#define ll  long long
#define FASTINOUT ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const ll mod = 1e9+7;
const int N=2e5+9;
int main()
{
    FASTINOUT;
    string s,t,a;
    cin>>s>>t>>a;
    if (s.back()==t[0]&&t.back()==a[0])
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return 0;
}
