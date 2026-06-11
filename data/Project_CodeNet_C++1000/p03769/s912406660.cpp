#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back

typedef long long ll;
typedef pair<int, int> pi;

ll n;

const int maxn = 105;

vector<int> f(ll X){
    if(X == 1){
        return vector<int>(0);
    }
    if(X & 1){
        vector<int> b = f(X - 1);
        vector<int> a(0);
        a.push_back(b.size() + 1);
        for(auto v : b){
            a.push_back(v);
        }
        return a;
    }else{
        vector<int> b = f(X / 2);
        b.push_back(b.size() + 1);
        return b;
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    vector<int> a = f(n + 1);
    cout << a.size() * 2 << endl;
    for(int i = 0;i < (int)a.size();i++){
        cout << a[i] << " ";
    }
    for(int i = 0;i < (int)a.size();i++){
        cout << i + 1 << " ";
        //cout << i + 1 << (i == a.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
