#include<iostream>
#include<map>
using namespace std;

const long long MOD=1000000007;

map<long long, int> fac_all;

void prime_factor(long long n){
    for(long long i=2; i*i<=n; i++){
        while(n%i==0){
            fac_all[i]++;
            n /= i;
        }
    }
    if(n!=1) fac_all[n]++;
}

int main(){
    //input
    long long N;
    cin >> N;

    //calc
    int i;
    for(i=2; i<=N; i++){
        prime_factor(i);
    }
    long long ans=1;
    for(auto p : fac_all){
        ans*=(long long)(p.second+1);
        ans%=MOD;
    }
    
    //output
    cout << ans << endl;
    system("pause");
    return 0;
}