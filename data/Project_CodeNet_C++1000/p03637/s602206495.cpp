#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const string YES = "Yes";
const string NO = "No";

void solve(long long N, std::vector<long long> a){
    vector<long long> b(3, 0);
    for(ll i = 0; i < N; ++i){
        if(a[i]%2) b[0]++;
        else if(a[i]%4) b[1]++;
        else b[2]++;
    }
    if(b[1]){
        if(b[2] < b[0]) cout << NO << endl;
        else cout << YES << endl;
    }else{
        if(b[2]+1 < b[0]) cout << NO << endl;
        else cout << YES << endl;
    }
    return;
}

int main(){
    long long N;
    scanf("%lld",&N);
    std::vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, std::move(a));
    return 0;
}
