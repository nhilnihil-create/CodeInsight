#include<bits/stdc++.h>
using namespace std;
typedef long long lint;

const int MAX_N = 1e5;
int N, K;
map<lint, lint> A;

int main(){
    cin >> N >> K;
    for(int i=0;i<N;i++){
        lint a, b; cin >> a >> b;
        auto it = A.find(a);
        if(it == A.end()) A[a] = b;
        else it->second += b; 
    }

    vector<int> bk(30);
    for(int i=0;i<30;i++){
        if((K>>i) & 1) bk[i] = 1;
        else bk[i] = 0;
    }

    lint ans = 0;
    for(auto it : A){
        bool ok = true;
        for(int j=0;j<30;j++)
            if((it.first>>j) & 1 == 1 &&  bk[j] == 0) ok = false;

        if(ok) ans += it.second;
    }

    for(int i=1;i<30;i++){
        if(!bk[i]) continue;

        lint res = 0; bk[i] = 0;
        for(auto it : A){
            bool ok = true;
            for(int j=i;j<30;j++)
                if((it.first>>j) & 1 == 1 &&  bk[j] == 0) ok = false;

            if(ok) res += it.second;
        }

        ans = max(ans, res);
    }

    cout << ans << endl;
    return 0;
}