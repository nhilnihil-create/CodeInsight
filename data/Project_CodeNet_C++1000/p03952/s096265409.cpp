#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<31)-1;


int main(){
    int N, x; cin >> N >> x;
    vector<int> X(2*N-1,INF);

    if(x==1 || x==2*N-1){ cout << "No" << endl;}
    else {
        X[N-2] = x-1; X[N-1] = x; X[N] = x+1;
        set<int> num;
        for(int i=1;i<=2*N-1;i++){
            if(abs(x-i)>1) num.insert(i);
        }
        rep(i,2*N-1){
            int xi = *num.begin();
            if(X[i]==INF){
                X[i] = xi;
                num.erase(xi);
            }
        }
        cout << "Yes" << endl;
        rep(i,2*N-1) cout << X[i] << endl;
    }

}