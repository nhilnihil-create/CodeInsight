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
    int a, b;
    cin >> a >> b;

    if(a+b >= 10){
        cout << "error" << endl;
    }else{
        cout << a+b << endl;
    }


    return 0;
}