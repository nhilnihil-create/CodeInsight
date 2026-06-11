#include <iostream>
#include <map>
using namespace std;

map<int, int> count;

void prime_factor(int n){
    for(int i=2; i*i<=n; i++){
        while(n%i == 0){
            count[i]++;
            n /= i;
        }
    }
    if(n!=1) count[n]++;
}

int main(){
    int n;
    long long ans = 1;
    const int M = 1000000007;
    cin >> n;
    for(int i=1; i<=n; i++){
        prime_factor(i);
    }
    for(int i=1; i<=n; i++){
        ans *= (count[i] + 1);
        ans %= M;
    }
    cout << ans << endl;
}

