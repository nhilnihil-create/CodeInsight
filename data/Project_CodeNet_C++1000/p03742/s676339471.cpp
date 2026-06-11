#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a,b;
int main()
{
    scanf("%d%d",&a,&b);
    printf(abs(a-b)<2?"Brown":"Alice");
}
