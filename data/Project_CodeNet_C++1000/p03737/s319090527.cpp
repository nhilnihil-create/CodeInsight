#include <bits/stdc++.h>
using namespace std;
using ll=long long;



int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

    string a,b,c;
    cin>>a>>b>>c;

    int diff='A'-'a';

    cout<<(char)(a[0]+diff)<<(char)(b[0]+diff)<<(char)(c[0]+diff)<<endl;

}
