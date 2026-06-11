#include <iostream>

using namespace std;

int main(){
    int W,H,N;
    cin>>W>>H>>N;
    int x[N],y[N],a[N];
    for(int i=0;i<N;i++){
        cin>>x[i];
        cin>>y[i];
        cin>>a[i];
    }
    int X[W] = {0};
    int Y[H] = {0};
    for(int i=0;i<N;i++){
        if(a[i]==1){
            for(int j=0;j<x[i];j++){
                X[j] = 1;
            }
        }else if(a[i]==2){
            for(int j=x[i];j<W;j++){
                X[j] = 1;
            }
        }else if(a[i]==3){
            for(int j=0;j<y[i];j++){
                Y[j] = 1;
            }
        }else{
            for(int j=y[i];j<H;j++){
                Y[j] = 1;
            }
        }
    }
    int xcounter = 0;
    int ycounter = 0;
    for(int i=0;i<W;i++){
        if (X[i] == 0){
            xcounter++;
        }   
    }
    for(int i=0;i<H;i++){
        if (Y[i] == 0){
            ycounter++;
        }
    }
    cout<<xcounter*ycounter<<endl;
}