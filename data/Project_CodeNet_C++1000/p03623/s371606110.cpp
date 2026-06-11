#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
#define rep(i,n) for(int i=0;i<(int)n;i++)
const ll INF = (1LL<<60);

int main(){
    int x,a,b; cin >> x >> a >> b;
    if(abs(x-a) > abs(x-b)) cout << "B" << endl;
    else cout << "A" << endl;
}