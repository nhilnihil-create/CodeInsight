#include <iostream>
#include <string.h>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n,a,b,i;
    long long int pa,pb,t;
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
        scanf("%d%d",&a,&b);
        if(i==0)
        {
            pa=a;
            pb=b;
        }
        else
        {
            if(a>=pa&&b>=pb)
            {
                pa=a*1ll;
                pb=b*1ll;
            }
            else if(a<pa||b<pb)
            {
                if((pa/a)>(pb/b))
                {
                    if(pa%a==0)
                    {
                        t=pa/a;
                        pa=t*a*1ll;
                        pb=t*b*1ll;
                    }
                    else
                    {
                        t=pa/a;
                        pa=t*a*1ll+a;
                        pb=t*b*1ll+b;
                    }
                }
                else
                {
                    if(pb%b==0)
                    {
                        t=pb/b;
                        pa=t*a*1ll;
                        pb=t*b*1ll;
                    }
                    else
                    {
                        t=pb/b;
                        pa=t*a*1ll+a;
                        pb=t*b*1ll+b;
                    }
                }
            }

        }
    }
    printf("%lld",pa+pb);
    return 0;
}