#include<iostream>
#include<cstdio>

using namespace std;
int main(){
    int W,H,N;
    cin>>W>>H>>N;
    int x[N],y[N],a[N];
    for(int i=0;i<N;++i)cin>>x[i]>>y[i]>>a[i];

    int x_min,x_max,y_min,y_max;
    x_min=0,x_max=W,y_min=0,y_max=H;
    
        for(int i=0;i<N;++i){
            switch (a[i])
            {
            case 1:
                if(x[i]>x_min)x_min=x[i];
                break;
            case 2:
                if(x[i]<x_max)x_max=x[i];
                break;
            case 3:
                if(y[i]>y_min)y_min=y[i];
                break;
            case 4:
                if(y[i]<y_max)y_max=y[i];
                break;
            
            }
        }
    if(x_min>x_max||y_min>y_max){
        cout<<"0";
    }else{
        cout<<(x_max-x_min)*(y_max-y_min);
    }

}
