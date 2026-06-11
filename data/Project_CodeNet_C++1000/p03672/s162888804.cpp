#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.size();

    int N = n;
    while(N >= 2){
        N -= 2;
        bool ok = true;
        rep(i,N/2){
            if(s[i] != s[i+N/2]){
                ok = false;
                break;
            }
        }
        if(ok){
            cout << N << endl;
            return 0;
        }
    }
}
