#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    int A, B, C; cin>> A >> B >> C;
    bool judge = false;

    rep(i, B){
        if(A*(i + 1) % B == C) judge = true;
    }

    if(judge) cout<< "YES" << endl;
    else cout << "NO" << endl;
}
