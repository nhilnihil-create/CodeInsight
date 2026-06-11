#include <bits/stdc++.h>
#define itn int
#define REP(i, n) for (int i = 0; i < (n); i++)
#define IREP(i, n) for (int i = n - 1; i >= 0; i--)
#define FOR(i, k, n) for (int i = (k); i < (n); i++)
#define REPEACH(itr, k) for (auto &&itr : k)
#define MOD 1000000007

using namespace std;
typedef long long ll;

const ll INF = 1LL << 60;


int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    set<int> s;
    REP(i,n){
        cin >> a[i];
        s.insert(a[i]);
    }
    if(s.size()%2==0){
        cout << s.size()-1 << endl;
    }
    else{
        cout << s.size() << endl;
    }
}