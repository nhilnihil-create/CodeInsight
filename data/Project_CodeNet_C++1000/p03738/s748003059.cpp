#include <algorithm>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
typedef long long ll;

#define rep(i, n) for(ll i = 0; i < n; i++)
#define REP(i, n) for(ll i = 1; i < n + 1; i++)
#define PI 3.14159265359
#define EPS 0.0000000001
#define MOD 1000000007
//cout << std::fixed << std::setprecision(15) << y << endl;


int main(){
    string A, B;
    cin >> A >> B;

    ll ans = 0;
    if(A.size() > B.size()){
        ans = -1;
    }else if(A.size() < B.size()){
        ans = 1;
    }else{
        rep(i, A.size()){
            if(A[i] > B[i]){
                ans = -1;
                break;
            }else if(A[i] < B[i]){
                ans = 1;
                break;
            }
        }
    }

    if(ans == -1){
        cout << "GREATER" << endl;
    }else if(ans == 0){
        cout << "EQUAL" << endl;
    }else{
        cout << "LESS" << endl;
    }

    return 0;
}