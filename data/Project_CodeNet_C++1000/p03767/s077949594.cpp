#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N; cin >> N;
    vector<long long> a(3*N);
    for(int i=0;i<3*N;i++){ cin >> a[i];}
    sort(a.begin(), a.end());
    long long ans = 0;
    for(int i=0;i<N;i++){
        ans += a[3*N-2-i*2];
    }
    cout << ans << endl;
}


