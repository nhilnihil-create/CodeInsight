#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <queue>
#include <string.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
typedef long long ll;
typedef pair<int,int> P;
int main() {
    string s;
    cin >> s;
    int a = 200001;
    int z = 0;
    rep(i, 0, s.size()){
        if(s[i]=='A'){
            a=min(i,a);
        }
        if(s[i]=='Z'){
            z=max(i,z);
        }
    }
    
    cout << z-a+1 << endl;
}