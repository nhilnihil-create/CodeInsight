#include<bits/stdc++.h>
#define ll long long
#define lu long unsigned

using namespace std;
bool sortbysec(const pair<int,int> &a,
              const pair<int,int> &b)
{
    return (a.second < b.second&&a.first<b.first);
}
bool isPrime(int val){
    for(int i=2;i*i<=val;i++){
        if(val%i==0)
            return false;
    }
    return true;
}

void solve(){
    ll int m=1000000007,n,ans=1;
    cin>>n;
    vector<int>primes;
    map<int,int>prime;
    for(int i=2;i<=n;i++){
        if(isPrime(i)){
            primes.push_back(i);
            prime[i]=0;
        }
    }
    for(lu int i=0;i<primes.size();i++){
        int x=primes[i];
        while(n/x!=0){
            prime[primes[i]]+=n/x;
            x*=primes[i];
        }
        prime[primes[i]]++;
        ans=ans%m*prime[primes[i]];
    }
    cout<<ans%m;


}


int main(){
    /*int t;
    cin>>t;
    while(t--)*/
        solve();


    return 0;
}
































































//1-(3+5-2+(3+19-(3-1-4+(9-4-(4-(1+(3)-2)-5)+8-(3-5)-1)-4)-5)-4+3-9)-4-(3+2-5)-10


















