#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N = pow(10,9)+7;

bool is_prime(int x){
    for(int i=2; i*i<=x; i++){
        if(x%i==0) return false;
    }
    return true;
}

int main(){
    int n;
    cin >> n;
    vector<int> prime;
    for(int i=2; i<=n; i++){
        if(is_prime(i)) prime.push_back(i);
    }
    vector<ll> cnt;
    for(int i=0; i<prime.size(); i++){
        int p=prime.at(i);
        ll time=0;
        for(int i=2; i<=n; i++){
            int calc=i;
            while(calc%p == 0){
                calc = calc/p;
                time++;
            }
        }
        cnt.push_back(time);
    }
    ll ans=1;
    for(int i=0; i<cnt.size(); i++){
        ans = (ans*(cnt.at(i)+1))%N;
    }
    cout << ans << endl;
}