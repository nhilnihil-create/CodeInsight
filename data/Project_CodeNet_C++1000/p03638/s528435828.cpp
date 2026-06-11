#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
long long mo = 1e9 + 7;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll H,W,N;
    cin >> H >> W >> N;
    vector<ll> a(N,0);
    rep(i,N){
        cin >> a[i];
    }
    ll cnt = 0;
    deque<ll> deq;
    rep(i,H){
        rep(j,W){
            if(a[cnt]>0){
                a[cnt]--;
            }else{
                a[++cnt]--;
            }
            if(i % 2 == 0){
                deq.push_back(cnt+1);
            }else{
                deq.push_front(cnt+1);
            }
        }
        rep(j,W){
            cout << deq.front() << " ";
            deq.pop_front();
        }
        cout << endl;
    }
}