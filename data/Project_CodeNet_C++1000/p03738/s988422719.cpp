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
    string A, B;
    cin >> A >> B;
    ll size_A,size_B;
    size_A = A.size();
    size_B = B.size();
    if(size_A != size_B){
        if(size_A > size_B){
            cout << "GREATER" << endl;
        }
        else{
            cout << "LESS" << endl;
        }
    }
    else{
        for(ll i=0;i<size_A;i++){
            if(A[i]!=B[i]){
                if(A[i]>B[i]){
                    cout << "GREATER" << endl;
                    break;
                }
                else{
                    cout << "LESS" << endl;
                    break;
                }
            }
            if((i==size_A-1)&&A[i]==B[i]){
                cout << "EQUAL" << endl;
            }
        }
    }
}