#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, const T& b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, const T& b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}

int main(){
    string move; cin >> move;

    int n=0, w=0, s=0, e=0;
    for(int i = 0; i < move.size(); i++){
        if(move[i] == 'N') n=1;
        if(move[i] == 'W') w=1;
        if(move[i] == 'S') s=1;
        if(move[i] == 'E') e=1;
    }

    if(n==s && w==e) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
