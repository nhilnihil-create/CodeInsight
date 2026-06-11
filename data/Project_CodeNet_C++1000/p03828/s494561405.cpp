#include <bits/stdc++.h>
using namespace std;
void factorization(long long n,map<long long ,long long>& mp){
    for(int i=2;i<=sqrt(n);i++){
        while(n%i==0){
            mp[i]++;
            n/=i;
        }

    }
    if(!(n==1))mp[n]++;
}
int main() {
    long long n;
    cin >> n;
map<long long,long long> factor;
for(int k=1;k<=n;k++){
factorization(k,factor);
}
long long ans=1;
for(auto i:factor){
    ans*=(i.second+1);
    ans%=1000000007;
}
cout << ans << endl;
}
