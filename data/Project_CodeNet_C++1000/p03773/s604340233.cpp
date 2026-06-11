#include <bits/stdc++.h>

using namespace std;

typedef unsigned long long ull;

#define rep(i,a,n) for (int i=a;i<n;i++)
#define loop(i,arr) for (auto i: arr)

int main()
{
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int a,b;cin>>a>>b;
    cout<<(a+b)%24<<endl;
    return 0;
}