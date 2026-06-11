#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

typedef long long ll;
typedef short int sh;

const int inf=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=1e9+7;

int main()
{
    int a,b,c;
    while(scanf("%d%d%d",&a,&b,&c)!=EOF)
    {
        if((a==5&&b==5&&c==7)||(a==5&&c==5&&b==7)||(b==5&&c==5&&a==7))
            puts("YES");
        else
            puts("NO");
    }
    return 0;
}
