#include <bits/stdc++.h>
using namespace std;
int N,K,m[5555],v[2][11111],x=1;
int main(){
    cin>>N>>K;
    v[0][0]=1;
    for(int i=0;i<N;i++)cin>>m[i];
    sort(m,m+N);
    int a=0,b=N,d=N;
    while(a<b){
        int c=(a+b)/2,pass=0;
        if(m[c]>=K){
            pass = 1;
            goto z;
        }
        v[0][0]=x;
        for(int i=0;i<N;i++){
            if(m[i]>=K)break;
            if(i==c)continue;
            for(int j=0;j<K;j++){
                if(v[0][j]==x){
                    v[1][j]=x;
                    v[1][j+m[i]]=x;
                    if(j+m[i]<K&&m[c]+j+m[i]>=K){
                        pass=1;
                        goto z;
                    }
                }
            }
            swap(v[0],v[1]);
        }
        z:
        if(pass){
            b=c;
            d=min(c,d);
        }
        else{
            a=c+1;
        }
        x++;
    }
    cout<<d<<endl;
}
