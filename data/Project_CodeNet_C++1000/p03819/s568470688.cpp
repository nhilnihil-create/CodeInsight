//© 2017 Jazengm/Zeng Xiangru, All Rights Reserved
#include<bits/stdc++.h>
using namespace std;

#define Re return
#define In inline
#define St static
#define Rg register
#define Op operator
#define Ct continue
#define inc(l, i, r) for(Rg int i=l; i<r; ++i)
#define dec(l, i, r) for(Rg int i=r; r>l; --i)
typedef long long ll;
typedef double db;

const int mxn = 3<<17;

int main()
{
    St int n, m;
    scanf("%d%d", &n, &m);
    St int c[mxn];
    inc(0, i, n)
    {
        St int l, r;
        scanf("%d%d", &l, &r), --l;
        for(Rg int i=1; i<=l;)
        {
            Rg int i_=min(l/(l/i), r/(r/i))+1;
            if(l/i!=r/i)
                ++c[i], --c[i_];
            i=i_;
        }
/*        for(Rg int i=1; i<=l;)
        {
            Rg int i_=r/(l/i+1), i__=l/(l/i)+1;
            if(i_>=i)
                ++c[i], --c[min(i_+1, i__)];
            i=i__;
        }*/
        ++c[l+1], --c[r+1];
    }
    Rg int ans=0;
    inc(1, i, m+1)
        printf("%d\n", ans+=c[i]);
    Re 0;
}
