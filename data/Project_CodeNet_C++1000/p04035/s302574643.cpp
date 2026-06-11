#include<bits/stdc++.h>
using namespace std;

int n,l,rope[100007],I;

void search()
{
    for(int i=1;i<n;++i) if(rope[i]+rope[i+1]>=l) {I=i; break;}
    if(I!=-1)
    {
        printf("Possible\n");
        for(int i=1,j=n-1;i<I || j>I;++i,--j)
        {
            if(i<I) printf("%i\n",i);
            if(j>I) printf("%i\n",j);
        }
        printf("%i\n",I);
    }
    else printf("Impossible\n");
}

void prepare()
{
    scanf("%i%i",&n,&l); I=-1;
    for(int i=1;i<=n;++i) scanf("%i",&rope[i]);
}

int main()
{
    prepare();
    search();
    return 0;
}