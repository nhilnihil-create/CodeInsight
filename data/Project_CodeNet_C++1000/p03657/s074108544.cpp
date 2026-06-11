#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a,b;cin>>a>>b;
    if (a%3==0||b%3==0||(a+b)%3==0)cout<<"Possible";
    else cout<<"Impossible";
    return 0;
}
