#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    int a, b;
    cin >> a >> b;
    if(a %3 == 0|| b % 3== 0 || (a + b) %3 ==0){
    	cout << "Possible" << endl;
    }else{
    	cout << "Impossible" << endl;
    }
    return 0;
}
