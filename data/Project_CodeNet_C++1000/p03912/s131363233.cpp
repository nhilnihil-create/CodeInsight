#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;

int main(){
    int N,M;
    cin>>N>>M;
    int X[100001];
    for(int i=0;i<N;i++){
        cin>>X[i];
    }
    if(M==1){
        cout<<N/2<<endl;
    }else{
        int dat[100001]={};
        int pai[100001]={};
        for(int i=0;i<N;i++){
            dat[X[i]]++;
        }
        int real_dat[100001]={};
        for(int i=0;i<=100000;i++){
            int z=i%M;
            real_dat[z] += dat[i];
            if(dat[i]>=2){
                pai[z]+=dat[i]/2;
            }
        }
        /*
         for(int i=0;i<M;i++){
         cout<<i<<' '<<real_dat[i]<<' '<<pai[i]<<endl;
         }*/
        int res=0;
        for(int i=0;i<=M/2;i++){
            int tmp;
            if(i==0){
                tmp=real_dat[i]/2;
                real_dat[i] -= 2*tmp;
                res += tmp;
            }else if(M%2==0 && i==M/2){
                tmp=real_dat[i]/2;
                real_dat[i] -= 2*tmp;
                res += tmp;
            }else{
                tmp = min(real_dat[i] , real_dat[M-i]);
                res += tmp;
                real_dat[i] -= tmp;
                real_dat[M-i] -= tmp;
            }
            //cout<<i<<' '<<tmp<<endl;
        }
        for(int i=1;i<M;i++){
            if(pai[i]!=0){
                res += min(real_dat[i]/2,pai[i]);
            }
        }
        cout<<res<<endl;
    }
    
    
    
    return 0;
}
