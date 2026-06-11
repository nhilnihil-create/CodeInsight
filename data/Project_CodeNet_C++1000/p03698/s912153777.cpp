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
    vector<int> alphabet(26,0);
    int size = S.size();
    for(int i=0;i<size;i++){
        int num = (int)(S[i]-'a');
        alphabet[num]++;
    }
    for(int i=0;i<26;i++){
        if(alphabet[i]>1){
            cout << "no" << endl;
            break;
        }
        else if(i==25){
            cout << "yes" << endl;
        }
    }
}