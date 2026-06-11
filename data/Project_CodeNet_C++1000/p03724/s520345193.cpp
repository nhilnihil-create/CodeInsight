#include<bits/stdc++.h>
using namespace std;
using Int = long long;
int main(){
    int N,M;
    cin >> N >> M;
    vector<int>cnt(N+1,0);
    for(int i = 0; i < M; ++i){
        int a,b; cin >> a >> b;
        cnt[a] += 1; cnt[b] += 1;
    }
    if(find_if(cnt.begin(),cnt.end(),[](int e){
        return (e % 2 != 0);
    }) == cnt.end()){
        return puts("YES") * 0;
    }
    cout << "NO" << endl;
}

