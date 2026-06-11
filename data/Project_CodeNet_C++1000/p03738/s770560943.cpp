#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <math.h>
#include <assert.h>
#include <set>
#include <map>
#include <bitset>
#include <ctime>
#include <time.h>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <stack>
#include <ctype.h>
#include <numeric>
#include <sstream>
#include <unistd.h>
#include <unordered_map>
#include <unordered_set>
#include <limits>
#include <random>
#include <chrono>
#include <iomanip>
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
using ll = long long;
#define endl '\n'
#define debug(name) DEBUG(#name, (name))
template<typename T>
void DEBUG(string label, T value) {
    cerr << "[" << label << " = " << value << "]\n";
}

void solve(){
    string a, b;
    cin >> a >> b;
    if(a.size() != b.size()){
        if(a.size() > b.size()){
            cout << "GREATER" << endl;
        }
        else{
            cout << "LESS" << endl;
        }
    }
    else{
        for(int i = 0; i < (int)a.size(); ++i){
            if(a[i] < b[i]){
                cout << "LESS" << endl;
                return;
            }
            else if(a[i] > b[i]){
                cout << "GREATER" << endl;
                return;
            }
        }
        cout << "EQUAL" << endl;
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    solve();
}
