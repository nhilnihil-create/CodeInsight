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
    string o,e;
    cin >> o >> e;
    vector<char>s(o.size()+e.size()+1);
    int index = 1;
    for(int i=0;i<o.size();i++){
        s[index]=o[i];
        index+=2;
    }
    
    index = 2;
    for(int i=0;i<e.size();i++){
        s[index]=e[i];
        index+=2;
    }
    for(int i=1;i<s.size();i++){
        cout << s[i];
    }
}
