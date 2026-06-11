#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;

int main() {
    int a,b,c;
    cin >> a>>b>>c;
    int dex = a;
    for(int i = a; i<=a*b; i+=dex){
        if(i%b == c) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}
