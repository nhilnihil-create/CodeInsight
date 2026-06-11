// 普通にわからなかった...
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

int main(){
    int w, h;
    cin >> w >> h;
    vector<pii> v;
    for(int i = 0; i < w; i++){
        int p;  cin >> p;
        v.push_back({p, 0});
    }
    for(int i = 0; i < h; i++){
        int p;  cin >> p;
        v.push_back({p, 1});
    }
    sort(v.begin(), v.end());
    w++, h++;
    ll ans = 0;
    for(pii p : v){
        if(p.second == 0){
            ans += (ll)h*p.first;
            w--;
        }else{
            ans += (ll)w*p.first;
            h--;
        }
    }
    cout << ans << endl;
    return 0;
}