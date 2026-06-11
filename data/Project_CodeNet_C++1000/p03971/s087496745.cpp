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
#include <iomanip>  //setprecision(桁)
using namespace std;
#define pb push_back
#define ll long long int
#define rep(i,n) for(int i = 0;i < (n);i++)
ll INF = 1000000010; 
const ll MOD = 1000000007;


int main(){ 
    int n, a, b; cin >> n >> a >> b;
    string s; cin >> s;
    int koku = 0, kai = 0, all = 0;

    rep(i,n){
        if(s[i] == 'c') cout << "No" << endl;
        else if(s[i] == 'a'){
            if(all < a + b) {
                cout << "Yes" << endl;
                all++;
            }
            else cout << "No" << endl;
        }else{
            if(all < a + b && kai < b) {
                cout << "Yes" << endl;
                kai++;
                all++;
            }
            else cout << "No" << endl;
        }
    }
}