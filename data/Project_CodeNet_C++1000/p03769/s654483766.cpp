#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N;
vector<int> ans;
int mem = 0;

int main()
{
    scanf("%lld",&N);

    for(int i = 40; i > 0; i--)
    {
        mem = i;
        if(N >= (ll)pow(2,i) - 1)break;
    }

    for(int i = 1; i <= mem; i++)ans.push_back(i);

    N -= (ll)pow(2,mem) - 1;

    for(int i = mem - 1; i >= 0; i--)
    {
        if(N < (ll)pow(2,i))continue;
        mem++;
        ans.insert(ans.begin() + i,mem);
        N -= (ll)pow(2,i);
    }
    printf("%d\n",2 * mem);
    for(int i = 0; i < ans.size(); i++)
    {
        printf("%d ",ans[i]);
    }
    for(int i = 1; i <= mem; i++)
    {
        printf("%d",i);
        if(i != mem)printf(" ");
    }printf("\n");

    return 0;

}
