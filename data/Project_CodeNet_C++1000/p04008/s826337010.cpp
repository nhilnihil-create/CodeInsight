#include <bits/stdc++.h>
using namespace std;

int ans = 0, N, K;
vector<int> child[100000];

int rec(int i){
    int num = 1;
    for(auto j : child[i]){
        num = max(num, rec(j) + 1);
    }
    if(num >= K){
        ans += 1;
        return 0;
    }else{
        return num;
    }
}

int main(){
    long long i, j, k;
    cin >> N >> K;
    for(i=0; i<N; i++){
        int a;
        cin >> a;
        if(i==0 && a != 1) ans += 1;
        if(i > 0) child[a-1].push_back(i);
    }
    for(auto i : child[0]){
        for(auto j : child[i]){
            rec(j);
        }
    }
    cout << ans << endl;
    return 0;
}