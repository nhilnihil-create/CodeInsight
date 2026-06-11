#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#include <vector>
#include <numeric>
#include <map>
#include <cmath>
#include <iomanip>
#include <queue>
using ll =long long;
using vi = vector<int>;
using vl = vector<ll>;
using vvi = vector<vi>;
using vs = vector<string>;

int main() {
    ll N;
    cin >> N;

    vl A(N);
    vl B(N);
    for(ll i=0; i<N; i++){
        cin >> A.at(i) >> B.at(i);
    }
    ll sum = 0;
    for(ll i=N-1; i>=0; i--){
        if((sum + A.at(i)) % B.at(i)==0){
            sum += 0;
        }
        else{
            sum += B.at(i) - ((sum + A.at(i)) % B.at(i));
        }
    }

    cout << sum << endl;
}