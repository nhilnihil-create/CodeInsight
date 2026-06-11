#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main() {
    int N;cin >> N;
    vector<int> a(N);
    for(int i=0;i<N;i++) {cin >> a[i];a[i]--;}
    int ans=0;
    for(int i=0;i<N;i++){
        if(a[a[i]] == i) ans++;
    }
    cout << ans/2 << endl;
}