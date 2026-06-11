#include <bits/stdc++.h>

using namespace std;

//FILE *fi=freopen("1.txt","r",stdin);

int n,m;
string s;

void nhap()
{
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            cin>>s;
            if (s=="snuke")
            {
                char c='A'+j-1;
                cout<<c<<i;
                return;
            }
        }
    }
}

int main()
{
    nhap();
    return 0;
}
