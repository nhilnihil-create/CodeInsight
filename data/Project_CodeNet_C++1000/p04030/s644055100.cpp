#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    string s;
    cin >> s;

    deque<ll> q;
    rep(i, s.size()){
        switch(s[i]){
            case '0':
                q.push_back(0);
                break;
            case '1':
                q.push_back(1);
                break;
            case 'B':
                if(!q.empty()){
                    q.pop_back();
                }
                break;
        }
    }

    while(!q.empty()){
        cout << q.front();
        q.pop_front();
    }
    cout << endl;

    return 0;
}