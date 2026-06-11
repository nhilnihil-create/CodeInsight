#include<cstdio>
#include<iostream>
using namespace std;

int main(){
    int W,H,n;
    while(~scanf("%d%d%d",&W,&H,&n)){
        int l=0,r=W,b=0,t=H;
        while(n--){
            int x,y,a;
            scanf("%d%d%d",&x,&y,&a);
            switch(a){
                case 1:
                    l=max(l,x);
                    break;
                case 2:
                    r=min(r,x);
                    break;
                case 3:
                    b=max(b,y);
                    break;
                default:
                    t=min(t,y);
            }
        }
        int ans;
        if(l>r||b>t)
            ans=0;
        else
            ans=(r-l)*(t-b);
        printf("%d\n",ans);
    }
    return 0;
}
