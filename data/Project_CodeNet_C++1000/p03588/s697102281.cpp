#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>
#include <map>
#include <iomanip>
#include <limits.h>
#include <queue>

using namespace std;    
typedef long long ll;
typedef pair<ll, ll> pll;
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
const bool DEBUG = false;


int main(){


    int N;
    cin >> N;

    ll minId = -1;
    ll minP = 1e10;
    ll maxId = -1;
    ll maxP = 0;



    for(int i = 0; i < N; i++){
        ll a, b;
        cin >> a >> b;
        if(b > maxP){
            maxP = b;
            maxId = a;
        }
        if(b <= minP){
            minP = b;
            minId = a;
        }

    }

    cout << minId + minP << endl;

}