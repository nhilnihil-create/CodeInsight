
#include <bits/stdc++.h>
using namespace std;

template<typename T>
void remove(std::vector<T>& vector, unsigned int index)
{
    vector.erase(vector.begin() + index);
}

typedef long long int ll;

ll INF = 1000000000000000000;
ll MOD = 1e9+7;

int main(){
    ll N,A,B;cin >> N >> A >> B;
    vector<ll> X(N);
    for(int i = 0;i < N;i++){
        cin >> X[i];
    }
    ll ans = 0;
    for(int i = 0;i < N-1;i++){
        ll d = X[i+1] - X[i];
        ans += min(A * d,B);
    }
    cout << ans << endl;
}
