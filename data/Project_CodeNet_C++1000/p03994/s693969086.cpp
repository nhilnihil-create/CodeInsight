#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const ll mod = 1000000007;
const int INF = 1001001001;

int main(){
    string s; cin >> s;
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int n = s.size();
    int k; cin >> k;
    vector<int> ss(n,-1);
    rep(i,n) ss.at(i) = (26 - (int)(s.at(i) - 'a'))%26;
    rep(i,n-1){
        if(k>=ss.at(i)){
            k -= ss.at(i);
            ss.at(i) = 26;        
        }
    }
    rep(i,n) ss.at(i) = 26 - ss.at(i);
    ss.at(n-1) = (ss.at(n-1)+k)%26;
    /*
    rep(i,n){
        cout << ss.at(i) << " " ;
    }
    */
    rep(i,n){
        cout << alphabet.at(ss.at(i));
    }
}
