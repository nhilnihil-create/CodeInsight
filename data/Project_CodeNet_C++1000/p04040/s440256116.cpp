#include <iostream>
using namespace std;

long long p = 1000000007;
long long mod_fact[200000];

void mod_fact_init(){
    mod_fact[0]=mod_fact[1]=1;
    for(int i=2;i<200000;i++){
        mod_fact[i]=(mod_fact[i-1]*i)%p;
    }
}


long long mod_pow(long long a,long long b){
    a%=p;
    if(b==0){
        return 1;
    }else if(b%2==0){
        return mod_pow(a*a,b/2)%p;
    }else{
        return (a*mod_pow(a,b-1))%p;
    }
}

long long mod_comb(long long a,long long b){
    long long c = (mod_fact[a]*mod_pow(mod_fact[a-b],p-2))%p;
    return (c*mod_pow(mod_fact[b],p-2))%p;
}

int main(void){
    long long h,w,a,b,c=0;
    cin>>h>>w>>a>>b;
    
    mod_fact_init();
    
    a=h-a-1;
    for(int i=0;a-i>=0&&b+i<=w-1;i++){
        c = (c+(mod_comb(a+b,a-i)%p)*(mod_comb(h-a+w-b-2,h-a-1+i)%p))%p;
    }
    cout<<c<<endl;
}
