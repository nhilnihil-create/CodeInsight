#include <iostream>
#include <map>
#define MOD 1000000000+7
using namespace std;

map<int, int> prime_factor(int n){
    map<int,int> prime_factor;
    for(int j=1;j<=n;j++){
        int x=j;
        for(int i=2;i*i<=x;i++){
            if(x==1) break;

            while(x%i==0){
                x /= i;
                prime_factor[i] ++;
            }
        }
        if(x>1) prime_factor[x] ++;
    }
    return prime_factor;
}

int main(void){
    int n;
    cin>>n;
    long long ans=1;
    for(auto kv: prime_factor(n)){
        ans *= (kv.second+1);
        ans %= MOD;
    }
    cout<<ans<<endl;
}