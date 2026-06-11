#include <bits/stdc++.h>
using namespace std;
using Int = int64_t;

int main(){
    Int N; cin >> N;
    vector<Int>A(N);
    for(auto& e : A) cin >> e;
    Int ans = A.front() - 1;
    Int mini =  2;
    A.erase(A.begin());
    for(auto e : A){
        if(mini >  e) continue;
        if( mini == e ){
            mini = mini + 1;
            continue;
        }
        if(e % (mini) == 0){
            ans += e / (mini) - 1; //mini++;
        } else {
            ans += e / (mini);
        }
    }
    cout << ans << endl;
}

