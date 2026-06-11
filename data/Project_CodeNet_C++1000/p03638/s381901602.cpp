#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i=0;i < (int)(n);i++)

int table[101][101];



int main(){
    int h,w;
    cin >> h >> w;
    int n;
    cin >> n;
    vector<int> v(n);
    rep(i,n){
        cin >> v[i];
    }
    bool f = true;
    int cnt = v[0];
    int now = 1;
    int id=0;
    rep(i,h){
        rep(j,w){
            table[i][j] = now;
            cnt--;
            if (cnt == 0){
                cnt = v[now];
                now++;
            }
        }
    }
    rep(i,h){
        if (i%2 == 1) reverse(table[i],table[i]+w);
    }
    rep(i,h){
        rep(j,w) cout << table[i][j] << " ";
        cout << endl;
    }
    return 0;
}