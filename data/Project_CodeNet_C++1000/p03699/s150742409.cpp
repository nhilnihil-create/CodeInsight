#include <bits/stdc++.h>
using namespace std;
#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
using ll = long long;

int main() {
    int N;
    cin >> N;
    vector<int> v(N);
    bool j = true;
    int b = 10000, sum = 0;
    rep(i, 0, N){
        cin >> v[i];
        sum += v[i];
        if(v[i]%10 != 0){
            int tempb = v[i];
            b = min(b, tempb);
            j = false;
        }
    }
    if(sum%10 != 0){
        cout<< sum << endl;
        }
    else if(j){
        cout << "0" << endl;
    }
    else{
        cout<< sum - b << endl;
        }
}