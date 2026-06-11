#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;

int main (){
    string s;
    cin >> s;

    if(s.size() >= 4){
        string tmp = s;
        tmp = tmp.substr(0, 4);
        if(tmp == "YAKI"){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }else{
        cout << "No" << endl;
    }


    return 0;
}