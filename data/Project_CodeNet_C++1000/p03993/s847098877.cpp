#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    int N;
    cin >> N;
    vector<vector<int>> a(N);
    int b[N];
    rep(i,0,N) {
        int tmp;
        cin >> tmp;
        b[i] = tmp-1;
        a[tmp-1].push_back(i);
    }

    int ans = 0;

    rep(i,0,N) {
        for (auto j:a[i]) {
            if (b[i]==j) {
                ans++;
            }
        }
    }
    ans/=2;
    cout << ans << endl;


}



