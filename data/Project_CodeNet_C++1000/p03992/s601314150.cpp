#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <ctime>
#include <cassert>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define fs first
#define sc second
#define INF 1000000000
#define MOD 1000000007
#define EPS 0.00000001


int main(){
    string S;  cin >> S;
    string ans;
    for(int i=0; i<(int)S.size(); i++){
        if(i==4) ans+=' ';
        ans += S[i];
    }
    cout << ans << endl;
    
    return 0;
}



