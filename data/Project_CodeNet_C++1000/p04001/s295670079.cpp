#include <bits/stdc++.h>
using namespace std;
long long res,p2[11],p10[11];
string s;
int main()
{
    cin>>s;
    int n=s.length();
    p2[0]=p10[0]=1;
    for (int i=1;i<=10;++i) {
        p2[i]=p2[i-1]*2;
        p10[i]=p10[i-1]*10;
    }
    for (int i=0;i<n;++i)
        for (int j=i;j<n;++j)
            res+=p2[i+max(0,n-j-2)]*(s[i]-'0')*p10[j-i];
    cout<<res<<endl;
    return 0;
}
