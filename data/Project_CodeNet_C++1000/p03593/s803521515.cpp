#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9+7;
const long long INF = 1e15;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int h,w;
    cin >> h >> w;
    string sur[h];
    for(int i = 0; i < h; i++) cin >> sur[i];

    int ald2 = 0,ald1 = 0;
    if(h%2 == 1 && w%2 == 1) ald1 = true;
    if(h%2 == 1) ald2 += w/2;
    if(w%2 == 1) ald2 += h/2;

    map<char,int> c;

    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            c[sur[i][j]]++;
            c[sur[i][j]] %= 4;
        }
    }

    auto rec = [&](int x){
        if(x < 0) cout << "No" << endl;
        return x < 0;
    };

    for(auto p:c){
        if(p.second != 0){
            if(p.second == 1){
                ald1--;
                if(rec(ald1)) return 0;
            } else if(p.second == 2){
                ald2--;
                if(rec(ald2)) return 0;
            } else {
                ald1--;
                ald2--;
                if(rec(ald1)) return 0;
                if(rec(ald2)) return 0;
            }
        }
    }
    if(ald1 != 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}