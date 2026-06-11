#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

vector<int> tonari[200005];

int main() {
    int N; cin>>N;
    vector<int> p(N);
    for (int i = 0; i < N; ++i) {
        cin>>p[i];
    }

    int ans=0;
    bool cont=false;

    for (int i = 0; i < N; ++i) {
        if(p[i]==i+1) {
            if (cont) {
                cont = false;
            } else {
                ans++;
                cont = true;
            }
        }else{
            cont=false;
        }
    }

    cout<<ans<<endl;

    return 0;
}