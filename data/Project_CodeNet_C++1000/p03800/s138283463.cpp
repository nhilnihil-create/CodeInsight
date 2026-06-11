#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;

int main() {
    int N; string s;
    cin>>N>>s;
    for (int i = 0; i < 4; ++i) {
        vector<bool> sheep(N+1,false);
        sheep[0]=(i&10);
        sheep[1]=(i&1);
        for (int i = 2; i <= N; ++i) {

            if(s[i-1]=='o'){
                sheep[i]=!(sheep[i-1]^sheep[i-2]);
            }else{
                sheep[i]=(sheep[i-1]^sheep[i-2]);
            }
        }
        //整合性
        if(sheep[0]==sheep[N] && ((s[0] == 'o')^sheep[0]) == (sheep[1] ^ sheep[N - 1])){
            for (int j = 0; j < N; ++j) {
                cout<<((sheep[j])?"S":"W");
            }
            cout<<endl;
            return 0;
        }
    }
    cout<<-1<<endl;
    return 0;
}
