#include <bits/stdc++.h>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
#include <iostream>

#include <bitset>
#include <cassert>
#include <queue>
#include <random>
#include <stack>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n;i++)
#define repf(i, a, b) for (int i = (int)a; i < (int)b;i++)
#define repv(x, arr) for (auto& x:arr)
#define all(v) (v).begin(), (v).end()
#define vec(name, num) vector<ll> name((num), 0);
#define mp(a,b) make_pair(a,b)
#define op(i) cout << (i) << endl;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pdd;

const ll mod = 1e9 + 7;



int main(){
    string S;
    cin >> S;
    int N = S.size();
    if (S[0]==S[N-1]){
        if (N%2==0){
            cout << "First" << endl;
        }
        else
        {
            cout << "Second" << endl;
        }
    }
    else{
        if(N%2==0)
        {
            cout << "Second" << endl;
        }
        else
        {
            cout << "First" << endl;
        }
    }
}
