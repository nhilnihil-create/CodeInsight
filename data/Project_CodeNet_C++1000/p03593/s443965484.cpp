#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <cmath>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <random>
#include <map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include <fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;

using ll = long long;
using vll = vector<ll>;
using pll = pair<ll, ll>;
using qll = queue<ll>;
using vb = vector<bool>;
using mll = map<ll, ll>;
using sll = stack<ll>;
#define REP(i,n) for(ll i(0);(i)<(n);(i)++)
#define rep(i,n) for(ll i(0);(i)<(n);(i)++)
#define ALL(a) a.begin(), a.end()
#define enld endl //* missspell check
const ll INF = 1LL << 60;
const string YES = "Yes";
const string NO = "No";


int main(){
    ll H, W;
    cin >> H >> W ;
    vector<string> S(H);
    REP(i, H){
        cin >> S[i];
    }
    map<char, ll> rec;
    REP(i, H){
        REP(j, W){
            rec[S[i][j]]++;
        }
    }
    /*
    ll nrQuad=0, nrDouble=0, nrSingle=0;
    for(auto x: rec){
        if(x.second % 4 == 0){
            nrQuad++;
        }
        else if(x.second % 2 == 0){
            nrDouble++;
        }
        else{
            nrSingle++;
        }
    }
    */

    priority_queue<ll > que;
    for(auto x:rec){
        que.push(x.second);
    }

    ll nrQuad, nrDouble, nrSingle;
    if(H % 2 == 0 && W % 2 == 0){
        nrQuad = H/2 * (W/2);
        nrDouble = nrSingle = 0;
        while(!que.empty()){
            if(nrQuad <= 0)
                break;
            auto x = que.top(); que.pop();
            if(x >= 4){
                nrQuad -= x/4;
                x %= 4;
                if(x > 0) que.push(x);
            }
            else{
                que.push(x);
                break;
            }
        }
        if(nrQuad > 0){
            cout << NO << endl;
            return 0;
        }
        cout << YES << endl;
    }
    else if(H % 2 == 0){
        nrQuad = H/2 * (W/2);
        nrDouble = H/2; nrSingle = 0;
        while(!que.empty()){
            if(nrQuad <= 0)
                break;
            auto x = que.top(); que.pop();
            if(x >= 4){
                nrQuad -= x/4;
                x %= 4;
                if(x > 0) que.push(x);
            }
            else{
                que.push(x);
                break;
            }
        }
        if(nrQuad > 0){
            cout << NO << endl;
            return 0;
        }
        while(!que.empty()){
            auto x = que.top(); que.pop();
            if(x >= 2){
                nrDouble -= x/2;
                x %= 2;
                if(x > 0) que.push(x);
            }
            else{
                que.push(x);
                break;
            }
        }
        if(nrDouble > 0){
            cout << NO << endl;
            return 0;
        }
        cout << YES << endl;
    }
    else if(W % 2 == 0){
        nrQuad = H/2 * (W/2);
        nrDouble = W/2; nrSingle = 0;
        while(!que.empty()){
            if(nrQuad <= 0)
                break;
            auto x = que.top(); que.pop();
            if(x >= 4){
                nrQuad -= x/4;
                x %= 4;
                if(x > 0) que.push(x);
            }
            else{
                que.push(x);
                break;
            }
                
        }
        if(nrQuad > 0){
            cout << NO << endl;
            return 0;
        }
        while(!que.empty()){
            auto x = que.top(); que.pop();
            if(x >= 2){
                nrDouble -= x/2;
                x %= 2;
                if(x > 0) que.push(x);
            }
            else{
                que.push(x);
                break;
            }
        }
        if(nrDouble > 0){
            cout << NO << endl;
            return 0;
        }
        cout << YES << endl;
    }
    else{ //* H odd, W odd
        nrQuad = H/2 * (W/2);
        nrDouble = H/2 + W/2; nrSingle = 1;
        while(!que.empty()){
            if(nrQuad <= 0)
                break;
            auto x = que.top(); que.pop();
            if(x >= 4){
                nrQuad -= x/4;
                x %= 4;
                if(x > 0) que.push(x);
            }
            else{
                que.push(x);
                break;
            }
        }
        if(nrQuad > 0){
            cout << NO << endl;
            return 0;
        }
        while(!que.empty()){
            auto x = que.top(); que.pop();
            if(x >= 2){
                nrDouble -= x/2;
                x %= 2;
                if(x > 0) que.push(x);
            }
            else{
                que.push(x);
                break;
            }
        }
        if(nrDouble > 0){
            cout << NO << endl;
            return 0;
        }
        cout << YES << endl;
    }



    return 0;
}
