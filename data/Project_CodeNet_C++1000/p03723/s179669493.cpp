#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for(ll i = 0; i < n; i++)
const ll INF = 1LL << 60;


int main(){
    int A, B, C, tA, tB, tC;
    cin >> A >> B >> C;
    tA = A; tB = B; tC = C;
    int ans = 0;
    while(1){
        if(A%2 == 1 ||B%2 == 1 || C%2 == 1)break;
        if(ans > 40){
            cout << - 1 << endl;
            return 0;
        }
        A = (tB + tC) / 2;
        B = (tA + tC) / 2;
        C = (tA + tB) / 2;
        tA = A;
        tB = B;
        tC = C;
        ans++;
    }
    cout << ans << endl;
}