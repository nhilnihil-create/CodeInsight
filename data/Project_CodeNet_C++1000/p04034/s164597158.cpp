#include<bits/stdc++.h>
using namespace std;

int n,m,box[100007],result;
int x[100007],y[100007];
bool b[1000007];

void prob()
{
    for(int i=0;i<m;++i)
    {
        if(b[x[i]]==true) b[y[i]]=true;
        --box[x[i]]; ++box[y[i]];
        if(box[x[i]]==0) b[x[i]]=false; 
    }

    for(int i=1;i<=n;++i) if(b[i]==true) ++result;
}

void prepare()
{
    scanf("%i%i",&n,&m); result=0;
    for(int i=0;i<m;++i) scanf("%i%i",&x[i],&y[i]);
    for(int i=0;i<100007;++i) box[i]=1; b[1]=true;
}

int main()
{
    prepare();
    prob();
    printf("%i\n",result);
    return 0;
}