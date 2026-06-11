#include <cstdio>
#include <cstring>
#include <cmath>
#include <utility>
#include <iostream>
#include <functional>
#include <bitset>
#include <algorithm>
#include <vector>
#include <forward_list>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <numeric>
#define ll long long int
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
int mx4[] = {0,1,0,-1};
int my4[] = {1,0,-1,0};
int INF = 2e6;
 

int main(){
    string s; cin >> s;
    int n = s.size();

    int l = n - 1;
    bool ok = true;
    while(l > 0) {
        if(s[l] == 'm' && s[l-1] == 'a' && s[l-2] == 'e' && s[l-3] == 'r' && s[l-4] == 'd') {
            l = l - 5;
            continue;
        }
        if(s[l] == 'e' && s[l-1] == 's' && s[l-2] == 'a' && s[l-3] == 'r' && s[l-4] == 'e') {
            l = l - 5;
            continue;
        }
        if(s[l] == 'r' && s[l-1] == 'e'){
            if(s[l-2] == 'm' && s[l-3] == 'a' && s[l-4] == 'e' && s[l-5] == 'r' && s[l-6] == 'd') {
                l = l - 7;               
                continue;
            }else if(s[l-2] == 's' && s[l-3] == 'a' && s[l-4] == 'r' && s[l-5] == 'e') {
                l = l - 6;
                continue;             
            }else{
                cout << "NO" << endl;
                return 0;
            }
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}