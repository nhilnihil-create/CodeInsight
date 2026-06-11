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
    string O,E;
    cin >> O >> E;
    int sizeo=O.size();
    int sizee=E.size();
    for(int i=0;i<(sizeo+sizee);i++){
        if(i%2==0){
            cout << O[i/2];
        }
        else{
            cout << E[(i/2)];
        }
    }
}