#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <list>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <cmath>
#define _GLIBCXX_DEBUG
using namespace std;
const long long INF = 1LL << 60;
typedef long long ll;
int main() {
    string S;
    cin >> S;
    int size = S.size();
    int cnt_N=0;
    int cnt_W=0;
    int cnt_S=0;
    int cnt_E=0;
    for(int i=0;i<size;i++){
        if(S[i]=='N'){
            cnt_N++;
        }
        else if(S[i]=='S'){
            cnt_S++;
        }
        else if(S[i]=='W'){
            cnt_W++;
        }
        else if(S[i]=='E'){
            cnt_E++;
        }
    }
    bool frg1 = true;
    if(cnt_N > 0){
        if(cnt_S>0){
            frg1 = true; // Yes
        }
        else{
            frg1 = false; // No
        }
    }
    if(cnt_S > 0){
        if(cnt_N>0){
            frg1 = true; // Yes
        }
        else{
            frg1 = false; // No
        }
    }
    bool frg2= true;
    if(cnt_W>0){
        if(cnt_E>0){
            frg2 = true;
        }
        else{
            frg2=false;
        }
    }
    if(cnt_E>0){
        if(cnt_W>0){
            frg2 = true;
        }
        else{
            frg2=false;
        }
    }
    if(frg1 && frg2){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}