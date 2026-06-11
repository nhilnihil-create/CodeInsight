#include<bits/stdc++.h>
#define int long long
using namespace std;

int qpow(int b,int e){
    if(!e)return 1;
    if(e&1) return qpow(b,e-1)*b;
    return qpow(b*b,e>>1);
}
int a[101][101];
int32_t main(){
    int w,h,n;
    cin>>w>>h>>n;
    int res=0;
    while(n--){
        int x,y,c;
        cin>>x>>y>>c;
        if(c==1)
            for(int i=0;i<x;i++)
                for(int j=0;j<h;j++)
                    a[i][j]=1;
        if(c==2)
            for(int i=x;i<w;i++)
                for(int j=0;j<h;j++)
                    a[i][j]=1;
        if(c==3)
            for(int i=0;i<w;i++)
                for(int j=0;j<y;j++)
                    a[i][j]=1;
        if(c==4)
            for(int i=0;i<w;i++)
                for(int j=y;j<h;j++)
                    a[i][j]=1;

    }

    for(int i=0;i<w;i++){
        for(int j=0;j<h;j++){
            if(!a[i][j])res++;
        }
    }

    cout<<res<<endl;

    return 0;
}
