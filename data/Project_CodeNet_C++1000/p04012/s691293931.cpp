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
    string w;
    cin >> w;
    int size = w.size();
    vector<int> alphabet(26,0);
    for(int i=0;i<size;i++){
        int num = (int)(w[i]-'a');
        alphabet[num]++;
    }
    for(int i=0;i<26;i++){
        if(alphabet[i]%2==1){
            cout << "No" << endl;
            break;
        }
        else if(i==25){
            cout << "Yes" << endl;
        }
    }
}