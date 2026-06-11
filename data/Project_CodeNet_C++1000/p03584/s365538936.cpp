#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<stack>
#include<set>
#include<climits>
#include<cstdlib>
#include<cmath>
#include<string>

using namespace std;

#define INF 1 << 29
#define LL long long int

LL const MOD = 1000000007;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    LL n,k;
    cin >> n >> k;
    vector<LL> a(n),b(n);
    for(int i = 0; i < n; i++){
        cin >> a[i] >> b[i];
    }
    
    LL bitlen = 1;
    while((1 << bitlen) <= k){
        bitlen++;
    }
    vector<LL> nbit(bitlen+1,0);
    for(LL j = 1; j < bitlen+1; j++){
        nbit[j] = nbit[j-1] + (1 << (j-1));
    }
    vector<LL> s;
    s.push_back(k);
    LL formask = 1 << bitlen;
    for(LL j = bitlen; j > 0; j--){
        LL jbit = 1 << (j-1);
        if(k&jbit){
            LL mask = formask - 1 - nbit[j];
            LL x = k&mask;
            x |= nbit[j-1];
            s.push_back(x);
        }
    }

    vector<LL> sum(s.size(),0);
    for(int i = 0; i < n; i++){
        for(int l = 0; l < sum.size(); l++){
            if((s[l]&a[i]) == a[i]){
                sum[l] += b[i];
            }
        }
    }

    LL ans = -1;
    for(int i = 0; i < sum.size(); i++){
        ans = max(ans,sum[i]);
    }

    cout << ans << endl;
    
    return 0;
}