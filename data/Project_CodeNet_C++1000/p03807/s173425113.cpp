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

    for(ll i=0; i <N; i++){
        cin >> A.at(i);
    }
    ll odd = 0;
    for(ll i=0; i <N; i++){
        if(A.at(i)%2 == 1){
            odd++;
        }
    }

    if(odd % 2 == 0){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

}