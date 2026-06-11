#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF (1LL<<50)
#define MOD 1000000007

int main(){
    int N,M;
    cin >> N >> M;
    vector<int>A;
    map<int,int> mp;
    rep(i,M){
        int a,b;
        cin >> a >> b;
        mp[a]++;
        mp[b]++;
        A.push_back(a);
        A.push_back(b);
    }
    for(int i=0;i<A.size();i++){
        if(mp[A[i]]%2==1){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}