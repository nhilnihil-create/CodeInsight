#include<bits/stdc++.h>
using namespace std;

bool check(int a1, int b1, int a2, int b2){
    if(a1 * b2 <= a2 * b1)return true;
    return false;
}

int main(){
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    set<int> st1, st2;
    for(int i = 0; i <= f; i++){
        for(int j = 0; j <= f; j++){
            int now1 = a * i + b * j;
            if(100 * now1 <= f)st1.insert(100 * now1);
            int now2 = c * i + d * j;
            if(now2 <= f)st2.insert(now2);
        }
    }
    int ans1 = 0, ans2 = 0;
    for(auto x : st1){
        for(auto y : st2){
            if(x + y > f || y > e * x / 100)continue;
            if(check(ans1, ans2, y, x+y)){
                ans1 = y; ans2 = x+y; 
            }
        }
    }
    cout << ans2 << " " << ans1 << endl;
}
