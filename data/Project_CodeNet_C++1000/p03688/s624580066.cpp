#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
vector<P> compress(map<int,int> mp){
    vector<P> vec;
    for(auto p:mp){
        vec.emplace_back(p);
    }
    return vec;
}
main(){
    int N;
    cin >> N;
    vector<int> V(N);
    rep(i,0,N)cin >> V[i];
    map<int,int> mp;
    rep(i,0,N)mp[V[i]]++;
    auto vec = compress(mp);
    if(vec.size() > 2 || vec.back().first - vec[0].first > 1){
        cout << "No" << endl;
        return 0;
    }
    if(vec.size() == 1){
        int num = vec[0].first;
        if(num == N-1 || num <= N/2){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
        return 0;
    }
    
    P p1 = vec[0], p2 = vec[1];
    int k = N - p2.first;
    int dif = p1.first - p1.second;
    if(dif <= k-1 && dif >= 0 && !(N % 2 == 0 && p1.second == 1)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}