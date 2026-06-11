#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<array>
#include<cstdio>
#include<bitset>
#include<vector>
#include<utility>
#include<sstream>
#include<cstring>
#include <climits>
#include <fstream>
#include<iostream>
#include<iomanip>
#include<algorithm>
#include <unordered_map>
using namespace std;
#define int long long

int32_t main(){
    string s;
    cin >> s;
    int i = 0;
    string cur = "";
    while( i < s.size() ){
        if( s[i] == ',' ){
            cout << cur << " ";
            cur = "";
        }
        else cur += s[i];
        i++;
    }
    cout << cur << endl;
}