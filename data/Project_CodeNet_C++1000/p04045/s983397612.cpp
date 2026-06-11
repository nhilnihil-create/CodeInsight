#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    int n, k; cin >> n >> k;
    vector<char> d(k);
    rep(i,k) cin >> d[i];
    for(int i = n; ; i++){
        bool isOK = true;
        string s = to_string(i);
        for(int j = 0; j < s.size(); j++){
            for(int l = 0; l < k; l++){
                if(s[j] == d[l]) isOK = false;
            }
        }
        if(!isOK) continue;
        else {
            cout << i << endl;
            return 0;
        }
    }
}