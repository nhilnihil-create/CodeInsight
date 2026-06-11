#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using p = pair<ll, ll>;

int main(){
    int n,m;
    cin >> n >> m;
    vector<p> stu, check;
    for(int i = 0; i < n; i++){
        ll a,b;
        cin >> a >> b;
        stu.push_back(p(a, b));
    }
    for(int i = 0; i < m; i++){
        ll c,d;
        cin >> c >> d;
        check.push_back(p(c, d));
    }
    for(int i = 0; i < n; i++){
        int ans = 0;
        ll norm = pow(10, 9);
        for(int j = 0; j < m; j++){
            if(abs(stu.at(i).first - check.at(j).first) 
                + abs(stu.at(i).second - check.at(j).second) < norm){
                    norm = abs(stu.at(i).first - check.at(j).first) 
                            + abs(stu.at(i).second - check.at(j).second);
                    ans = j;
                }
        }
        cout << ans + 1 << endl;
    }
}