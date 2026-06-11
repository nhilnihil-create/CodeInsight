#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define FOR(i,a,n) for(ll i=a;i<(ll)(n);i++)

int main(){
    long n;
    cin>>n;
    deque<long> que;
    rep(i, n){
        long a; cin>>a;
        if(i%2 == 0) que.push_back(a);
        else que.push_front(a);
    }

    rep(i, n){
        if(n%2 == 1){
            cout << que.back();
            que.pop_back();
        }else{
            cout << que.front();
            que.pop_front();
        }

        if(i != n-1){
            cout << " ";
        }else{
            cout << endl;
        }
    }
}
