#include <bits/stdc++.h>
using namespace std;

void solve(long long N, std::vector<long long> s){
    sort(s.begin(), s.end());
    int sum = 0;
    for ( auto it = s.begin(); it != s.end();  ) {
       auto f = *it;
       it++;
       sum += f;
       it++;
    }
    cout << sum << endl;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> L(2*N);
    for(int i = 0 ; i < 2*N ; i++){
        scanf("%lld",&L[i]);
    }
    solve(N, std::move(L));
    return 0;
}
