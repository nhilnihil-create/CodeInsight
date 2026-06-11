#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using ll = long long int;
const int INF = (1<<30);
const ll INFLL = (1ll<<60);
const ll MOD = (ll)(1e9+7);

#define l_ength size

void mul_mod(ll& a, ll b){
	a *= b;
	a %= MOD;
}

void add_mod(ll& a, ll b){
	a = (a<MOD)?a:(a-MOD);
	b = (b<MOD)?b:(b-MOD);
	a += b;
	a = (a<MOD)?a:(a-MOD);
}

int main(void){
    int k,n,i;
    std::string s;
    std::cin >> s;
    n = s.l_ength()-1;
    std::cin >> k;
    for(i=0; i<n; ++i){
        if(('{'-s[i])%26>k){
            continue;
        }
        k -= ('{'-s[i])%26;
        s[i] = 'a';
    }
    k += s[n]-'a';
    k %= 26;
    s[n] = 'a'+k;
    std::cout << s << std::endl;
	return 0;
}
