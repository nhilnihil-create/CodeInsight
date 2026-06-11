#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;

int main(){
    int n;
    long long mod=1e9+7;
    cin>>n;
    vector<long long>d(1000);
    long long ans=1;
    for(int i=2;i<=n;i++){
        int x=i;
        for(int j=2;j<=x;j++){
            while(x%j==0){
                x/=j;
                d[j]++;
            }
        }
    }
    for(int i=0;i<=1000;i++){
        ans*=(d[i]+1);
        ans%=mod;
    }
    cout<<ans<<endl;
    return 0;
}