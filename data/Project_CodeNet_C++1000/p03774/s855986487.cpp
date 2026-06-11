
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int n, m; //nは学生の数、mはチェックポイントの数
    cin >> n >> m;
    //学生の位置
    vector<int64_t> a(n);
    vector<int64_t> b(n);
    rep(i,n){
        cin >> a.at(i);
        cin >> b.at(i);
    }
    //チェックポイントの位置
    vector<int64_t> c(m);
    vector<int64_t> d(m);
    rep(i,m){
        cin >> c.at(i);
        cin >> d.at(i);
    }

    vector<int> ans(n);
    rep(i,n){
        int64_t dis;
        int64_t ansdis = 10000000000;
        rep(j,m){
            dis = abs(a.at(i) - c.at(j)) + abs(b.at(i)-d.at(j));
            if(dis < ansdis){
                ansdis = dis;
                ans.at(i) = j + 1;
            }
        }
    }
    rep(i,n){
        cout << ans.at(i) << endl;
    }
    
}