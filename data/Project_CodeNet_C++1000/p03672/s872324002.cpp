#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

int main(){
    string s; cin >> s;
    int n = s.size();
    for(int i = n-2; i > 0; i-=2){
        string t = s.substr(0, i);
        if(t.substr(0,i/2) == t.substr(i/2,i/2)) {
            cout << t.size() << endl;
            return 0;
        }
    }
}