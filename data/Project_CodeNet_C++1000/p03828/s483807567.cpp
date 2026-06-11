#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

const long long MAX = 1e9+7;

vector<bool> is_prime(1001, true);

void sieve_of_eratosthenes(int n){
	is_prime[0] = is_prime[1] = false;

	for (int i=2; i<=n; i++)
        if(is_prime[i] &&  i*i*1ll<=n)
            for (int j=i*i*1ll; j<=n; j+=i)
                is_prime[j] = false;
}

int legendre(int n){

    ll res = 1;
    for (int i=1; i<=n; i++){
        if(is_prime[i]){

            ll sum_expo = 0;
            ll pot = 1;
            while((n/pot)>0){
                pot = pot * i;
                sum_expo += n/pot;
            }

            if(sum_expo == 0) break;
            res = (res * (sum_expo + 1))%MAX;
        }
    }
    return res;
}

void solve(){
    int n; cin>>n;
    sieve_of_eratosthenes(n);
    cout<<legendre(n)<<endl;
}

int main(){
    solve();
    return 0;
}
