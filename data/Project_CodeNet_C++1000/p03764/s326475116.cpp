#include <algorithm>
#include <iostream>
#include <cmath>

const int MOD = 1E9+7;
using namespace std;


long long ans[100005];
long long res[100005];

int main(){
    int n,m;
    cin>>n>>m;
    for (int i=0;i<n;i++){
        cin>>ans[i];
    }
    for (int j=0;j<m;j++){
        cin>>res[j];
    }
    long long x=0,y=0,result=0;
    for (long long i=0;i<n;i++){
        x=(x+i*ans[i])%MOD;
        x=(x-(n-i-1)*ans[i]%MOD+MOD)%MOD;
    }
    for (long long i=0;i<m;i++){
        y=(y+i*res[i])%MOD;
        y=(y-(m-i-1)*res[i]%MOD+MOD)%MOD;
    }
    result = (x*y)%MOD;
    cout<<result<<endl;
}
