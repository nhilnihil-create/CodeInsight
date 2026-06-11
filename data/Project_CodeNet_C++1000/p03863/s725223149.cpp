#define _USE_MATH_DEFINES

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

using namespace std;

typedef pair<long long int, long long int> P;

long long int INF = 1e18;
long long int MOD = 1e9 + 7;

int main(){
    string str;
    cin >> str;
    if((str[0] == str[str.size() - 1]) ^ (str.size() % 2 == 1)){
        cout << "First" << endl;
    }else{
        cout << "Second" << endl;
    }
    return 0;
}