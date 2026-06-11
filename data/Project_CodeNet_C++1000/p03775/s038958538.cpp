#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n; cin>>n;

    long long int a,b,f,min=10000000000;
    
    // 整数/0をやるとfloatin point exceptionのエラーが出るのでi=1から始める
    // i*i<=nでやってもiはなぜかこの条件をすり抜ける
    for(int i=1;i<=n/i;i++){
        f=1;
        if(n%i==0){
            a=i;
            b=n/a;
            while(b>0){
                if(b/10!=0){
                    f++;
                }
                b/=10;
            }
            if(f<min) min=f;
        }
    } 

    cout<<min<<endl;
}