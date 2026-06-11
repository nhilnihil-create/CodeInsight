#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <cassert>
#include <utility>
#include <string>
#include <cmath>
#include <set>
#include <map>
#include <thread>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; ++i)
typedef long long ll;
typedef pair<int,int> pii;
int main(){
    int a,b;
    cin >> a >> b;
    string s;
    rep(i,a)rep(j,b){
        cin >> s;
        if(s=="snuke"){
            cout << char('A'+j) << i+1 << endl;
            return 0;
        }
    }
}
