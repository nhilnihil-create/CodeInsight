#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(void) {
    ll N, tmp;
    int num = 0;
    cin >> N;
    tmp = N + 1;
    vector<int> ans;

    while(tmp) {tmp /= 2; num++;}
    for(int i=0; i<num-1; i++) {
        if(((N+1) >> i) & 1) ans.emplace_back(100-i);
        ans.emplace_back(i+1);
    }

    printf("%d\n", ans.size()+100);
    for(int a : ans) printf("%d ", a);
    for(int i=1; i<=100; i++) printf("%d ", i);
    printf("\n");
    return 0;
}