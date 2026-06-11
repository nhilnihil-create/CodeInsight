#include<bits/stdc++.h>
using namespace std;
const int mx = 100005;
int n, a, m[mx], mi[mx], mlen, j = 1;
long long ms[mx], mr[mx];
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a);
        if(a > m[mlen]){
            m[++mlen] = a;
            ms[mlen] = 1;
            mi[mlen] = i;
        }else if(a == m[mlen]) ms[mlen]++;
        else{
            int it = upper_bound(m, m+mlen+1, a) - m;
            mr[it] += a - m[it-1];
            ms[it-1]++;
        }
    }
    for(int i = mlen; i > 0; i--){
        mr[i] += ms[i] * (m[i] - m[i-1]);
        ms[i-1] += ms[i];
    }
    for(int i = 0; i < n; i++) printf("%lld\n", mi[j] - i ? 0 : mr[j++]);
}