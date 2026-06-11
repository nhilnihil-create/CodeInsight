#include<bits/stdc++.h>
using namespace std;
int N;
vector<int> G[100010];
template<class T> void chmax(T& x, T y) {if(x < y) x = y;}
int rnk(int n){
    int mx = 0;
    vector<int> vs;
    for(auto& u : G[n]){
        vs.push_back(rnk(u));
    }
    sort(vs.rbegin(), vs.rend());
    for(int i = 0; i < vs.size(); i++){
        chmax(mx, vs[i] + i);
    }
    return mx + 1;
}

int main(){
    cin >> N;
    for(int i = 2; i <= N; i++){
        int a;
        cin >> a;
        G[a].push_back(i);
    }
    cout << rnk(1) - 1 << endl;
    return 0;
}