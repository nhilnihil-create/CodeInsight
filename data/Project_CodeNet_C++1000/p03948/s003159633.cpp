#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
 
    int n,t;
    scanf("%d%d",&n,&t);
 
    int cot = 1, minn , maxx = -10;
    int c,tc;
    for(int i=0;i<n;i++)
    {
        scanf("%d",&c);
        if(i)
        {
            if(c>tc)
            {
                if(c-minn>maxx)
                    maxx=c-minn,cot = 1;
                else if(c-minn==maxx)
                    cot++;
            }
            if(minn>c)
                minn = c;
        }
        else
            minn = c;
        tc = c;
    }
    cout<<cot<<endl;
 
 
 
    return 0;
}