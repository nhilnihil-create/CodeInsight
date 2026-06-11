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
int main() {
    int N,A,B;
    cin >> N >> A >> B;
    string S;
    cin >> S;
    int size = S.size() ;
    int cnt_A = 0;
    int cnt_B = 0;
    for(int i=0;i<size;i++){
        int total=cnt_A+cnt_B;
        if(S[i]=='a'){
            if(total<(A+B)){
                cout << "Yes" <<endl;
                cnt_A++;
            }
            else{
                cout << "No" <<endl;
            }
        }
        else if(S[i]=='b'){
            if( (total < (A+B)) && (cnt_B < B) ){
                cout << "Yes" << endl;
                cnt_B++;
            }
            else{
                cout << "No" <<endl;
            }
        }
        else if(S[i]=='c'){
            cout << "No" <<endl;
        }
    }
}