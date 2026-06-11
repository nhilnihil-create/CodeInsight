#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll N;
    cin >> N;
    map<ll,ll> A;
    ll tmp;
    rep(i,N){
        cin >> tmp;
        A[tmp]++;
    }
    ll size = A.size();
    ll cnt = 0;
    for(auto& p:A){
        if(p.second >= 2){
            if(p.second % 2 == 0){
                cnt++;
            }
        }
    }
    cnt = cnt % 2;

    cout << size - cnt << endl;
}
/*
1 3 5 2 1 3 2 8 8 6 2 6 11 1 1
1 3 5 2 1 3 2 8 8 6 2 6 11
1 3 5 2 1 3 8 8 6 6 11


*/