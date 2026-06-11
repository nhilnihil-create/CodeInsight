#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;
typedef long long ll;
#define INF ((ll)1e18)

int N;
ll a[(int)3e5];
ll lmax[(int)(1e5+1)];
ll rmin[(int)(1e5+1)];

int main(){
    cin >> N;
    for(int n=0; n<3*N; n++){
        cin >> a[n];
    }
    
    priority_queue<ll,vector<ll>,greater<ll> > que;
    lmax[0]=0;
    for(int i=0; i<N; i++){
        lmax[0] += a[i];
        que.push(a[i]);
    }
    for(int i=1; i<=N; i++){
        que.push(a[N+i-1]);
        lmax[i] = lmax[i-1] - que.top() + a[N+i-1];
        que.pop();
    }
    for(int i=0; i<=N; i++){
        cerr << i << ": " << lmax[i] << endl;
    }
    
    priority_queue<ll> que2;
    rmin[0]=0;
    for(int i=0; i<N; i++){
        rmin[0] += a[3*N-1-i];
        que2.push(a[3*N-1-i]);
    }
    for(int i=1; i<=N; i++){
        que2.push(a[2*N-i]);
        rmin[i] = rmin[i-1] - que2.top() + a[2*N-i];
        que2.pop();
    }
    for(int i=0; i<=N; i++){
        cerr << i << ": " << rmin[i] << endl;
    }
    
    ll res = -INF;
    for(int i=0; i<=N; i++){
        ll tmp;
        tmp = lmax[i] - rmin[N-i];
        if(tmp>res) res=tmp;
    }
    cout << res << endl;
    
    return 0;
}
