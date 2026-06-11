#include <iostream>
using namespace std;

long long p(long long a,long long b){
    if(b==0){
        return 1;
    }else if(b%2==0){
        return p(a*a,b/2);
    }else{
        return a*p(a,b-1);
    }
}

int main(void){
    long long n,k[32],l=1,c[32];
    bool f=false;
    cin>>n>>k[0];
    c[0]=0;
    for(int i=0;i<32;i++){
        if(f&&(1&(k[0]>>i))==1){
            k[l]=k[0]-k[0]%p(2,i)-1;
            c[l]=0;
            l++;
        }else if((1&(k[0]>>i))==0){
            f=true;
        }
    }
    for(int i=0;i<n;i++){
        long long a,b;
        cin>>a>>b;
        for(int j=0;j<l;j++){
            bool f=true;
            for(int m=0;m<32;m++){
                if((k[j]>>m)%2==0&&(a>>m)%2==1){
                    f=false;
                }
            }
            if(f){
                c[j]+=b;
            }
        }
    }
    for(int i=1;i<l;i++){
        c[0]=max(c[0],c[i]);
    }
    cout<<c[0]<<endl;
}
