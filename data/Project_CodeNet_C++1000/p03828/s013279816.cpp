#include<bits/stdc++.h>
using namespace std;
int main(){
    const int mod=1000000007;
    int n;
    cin>>n;
    int x[n+1]={};
    for(int i=2;i<=n;i++){
        int I=i;
        for(int j=2;j<=sqrt(I);j++){
            while(I%j==0){
                x[j]++;
                I/=j;
            }
        }
        if(I>1)x[I]++;
    }
    long long factor=1;
    for(int i=2;i<=n;i++){
        factor*=(x[i]+1);
        factor%=mod;
    }
    cout<<factor<<endl;
    return 0;
}