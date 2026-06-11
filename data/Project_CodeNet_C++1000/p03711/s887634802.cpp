#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; ++i)
#define all(x) (x).begin(),(x).end()
#define endl "\n"

using ll = long long;
using P = pair<int,int>;
using mp =  map<char,int>;

const int MOD = 1e9 + 7;
const int INF = 1001001001;


int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

    int x, y;
    cin >> x >> y;

    if(x == 2){
        x = 3;
    }else if(x == 4 || x == 6 || x == 9 || x == 11){
        x = 2;
    }else{
        x = 1;
    }

    if(y == 2){
        y = 3;
    }else if(y == 4 || y == 6 || y == 9 || y == 11){
        y = 2;
    }else{
        y = 1;
    }

    if(x == y){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    

    return 0;
}