#include <iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<limits>
#include<string.h>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

int main()
{
    int n,m;
    cin>>n>>m;
    int k=0;
    int x[100100];
    for(int i=0;i<n;i++){
        cin>>x[i];
    }
    int y[100100]={};
    for(int i=0;i<n;i++){
        y[x[i]]+=1;
    }
    int z[100100]={};
    int w[100100]={};
    for(int i=0;i<100001;i++){
        z[i%m]+=y[i];
        w[i%m]+=(y[i]/2);
    }
    if(m%2==1){
        k+=z[0]/2;
        for(int i=1;i<=m/2;i++){
            if(z[i]>=z[m-i]){
                k+=z[m-i];
                if((z[i]-z[m-i])/2>=w[i]){
                    k+=w[i];
                }else
                {
                    k+=(z[i]-z[m-i])/2;
                }
            }else
            {
                k+=z[i];
                if((z[m-i]-z[i])/2>=w[m-i]){
                    k+=w[m-i];
                }else
                {
                    k+=(z[m-i]-z[i])/2;
                }
            }
        }
        
    }else
    {
        k+=z[0]/2;
        k+=z[m/2]/2;
        for(int i=1;i<m/2;i++){
            if(z[i]>=z[m-i]){
                k+=z[m-i];
                if((z[i]-z[m-i])/2>=w[i]){
                    k+=w[i];
                }else
                {
                    k+=(z[i]-z[m-i])/2;
                }
            }else
            {
                k+=z[i];
                if((z[m-i]-z[i])/2>=w[m-i]){
                    k+=w[m-i];
                }else
                {
                    k+=(z[m-i]-z[i])/2;
                }
            }

        }
    

    }

    cout<<k<<endl;
    

    

    return 0;
}