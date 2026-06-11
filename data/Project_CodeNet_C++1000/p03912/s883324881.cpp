#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll input[100001];
vector<ll> mod[100001];
ll c[100001];
ll ps[100001];

int main(){
    ll N,M,x;
    cin >> N >> M;
    for(int i=0;i<=100000;i++){
        input[i] = 0;
        c[i] = 0;
        ps[i] = 0;
    }
    for(int i=0;i<N;i++){
        cin >> x;
        input[x]++;
    }
    for(int i=0;i<=100000;i++){
        if(input[i] != 0){
            mod[i%M].push_back(input[i]);
            c[i%M] += input[i];
            ps[i%M] += input[i] / 2;
        }
    }
    for(int i=0;i<M;i++){
        sort(mod[i].begin(),mod[i].end());
    }
    ll ans = 0;
    for(int i=0;i<=M/2;i++){
        if(i==M-i || i%M==0){
            ans += c[i]/2;
            //cout << i << " " << ps[i] << endl;
            continue;
        }
        ll b = min(c[i],c[M-i]);
        ans += b;
        //cout << i << " " << b << endl;
        if(b < c[i]){
            ans += min(ps[i],(c[i]-b)/2);
            //cout << i << " " << min(ps[i],(c[i]-b)/2) << endl;            
        }
        if(b < c[M-i]){
            ans += min(ps[M-i],(c[M-i]-b)/2);
            //cout << i << " " << min(ps[M-i],(c[M-i]-b)/2) << endl;            
        }
    }
    cout << ans << endl;
    return 0;
}