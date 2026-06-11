#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int a,b,c;cin>>a>>b>>c;

    bool ans=false;

    for(int i=1;i<=b;i++)if((a*i)%b==c)ans=true;

    puts(ans?"YES":"NO");

    return 0;
}
