#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;
typedef short int sh;

const int inf=0x3f3f3f3f;
const int MAX=2e5+10;
const int mod=1e9+7;
char ans[MAX],in[MAX];
int main()
{
    while(scanf("%s",in)!=EOF)
    {
        int i,j=0;
        for(i=0;in[i];i++)
        {
            if(in[i]=='B')
            {
                if(j)
                    j--;
            }
            else
            {
                ans[j++]=in[i];
            }
        }
        ans[j]=0;
        puts(ans);
    }
    return 0;
}
