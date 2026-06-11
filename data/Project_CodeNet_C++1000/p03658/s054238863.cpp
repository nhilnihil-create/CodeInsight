#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define rep2(i,n) for(int i=1; i<=(n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define all(x) (x).begin(),(x).end()
#define Sort(x) sort((x).begin(),(x).end())
#define Sort2(x) sort((x).begin(),(x).end(), greater<int>())
const int INF = 1001001001;

int main()
{
    int n,k; cin >> n >> k;
    vector<int> l(n); rep(i, n) cin >> l[i];
    Sort2(l);
    int sum = 0;
    rep(i,k) sum += l[i];
    cout << sum << endl;
}

/*
Ctrl+@
g++ a.cpp
./a.out
*/