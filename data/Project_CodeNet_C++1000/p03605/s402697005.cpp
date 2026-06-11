#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int n; cin >> n;
    int d1 = n%10;
    int d2 = (n/10);

    if(d1 == 9 || d2 == 9) cout << "Yes" << endl;
    else cout << "No" << endl;
}