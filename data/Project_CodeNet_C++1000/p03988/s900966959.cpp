#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) a.begin(), a.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;

int main(){

    int n;
    cin >> n;

    int biggest = 0;
    map<int, int> mp;
    rep(i, n){
        int a;
        cin >> a;
        chmax(biggest, a);
        mp[a]++;
    }

    bool answer = true;
    auto itr = mp.begin();
    int now = (*itr).first;
    if(biggest % 2 == 0){
        if((*itr).second != 1)answer = false;
        if(now * 2 != biggest)answer = false;
    } else {
        if((*itr).second != 2)answer = false;
        if(now * 2 - 1 != biggest)answer = false;
    }
    for(itr++; itr != mp.end(); itr++){
        if(now + 1 != (*itr).first)answer = false;
        now = (*itr).first;
    }
    
    cout << (answer ? "Possible\n" : "Impossible\n");
    return 0;

}