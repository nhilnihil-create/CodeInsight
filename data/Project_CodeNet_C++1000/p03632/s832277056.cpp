
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> second(101,0);
    rep(i,101){
        if(a < i && i <= b){
            second.at(i) ++;
        }
        if(c < i && i <= d){
            second.at(i) ++;
        }
    }
    //second==2が二人ともスイッチを押している時間
    int count=0;
    rep(i,101){
        if(second.at(i) == 2) count ++;
    }
    cout << count << endl;

    
}