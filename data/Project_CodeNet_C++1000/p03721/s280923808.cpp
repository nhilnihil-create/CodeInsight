#include <bits/stdc++.h>
using namespace std;
#define PI 3.141592653589793
#define MOD 1000000007
typedef long long ll;
typedef long double ld;


int main() {
    ll N, K;
    cin >> N >> K;
    K--;
    vector<pair<ll,ll>> A;
    for(int i = 0; i < N; i++){
        ll tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        A.push_back(make_pair(tmp1,tmp2));
    }
    sort(A.begin(),A.end());
    int i = 0;
    while(1){
        K -= A[i].second;
        if(K < 0){
            break;
        }
        i++;
    }
    cout << A[i].first << endl;
}