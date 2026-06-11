#include <iostream>
#include <vector>
#include <climits>

using namespace std;

const int p = 1000000007;
vector<int> fact;
vector<int> inv;
vector<int> factinv;

int combi(int a, int b){
    return (int)((long long)fact[a]*factinv[a-b]%p*factinv[b]%p);
}
int main(){
    int h, w, a, b;
    cin >> h >> w >> a >> b;
    int size=h+w-2;
    fact = vector<int>(size);
    inv = vector<int>(size);
    factinv = vector<int>(size);
    fact[0]=1, factinv[0]=1;
    fact[1]=1, inv[1]=1, factinv[1]=1;
    for(int i=2;i<size;++i){
        fact[i] = (int)((long long)fact[i-1]*i % p);
        inv[i] = p - (int)((long long)inv[p%i] * (p/i) % p);
        factinv[i] = (int)((long long)factinv[i-1]*inv[i] % p);
    }
    long long ans=0;
    for(int i=b+1;i<=w;++i){
        ans = (ans + (long long)combi(h-a-1+i-1, i-1) * combi(a-1+w-i, w-i) % p) % p;
    }
    cout << ans;
    return 0;
}