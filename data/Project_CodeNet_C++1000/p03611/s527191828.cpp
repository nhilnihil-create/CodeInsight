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
    ll N;
    cin >> N;

    ll a[N];
    ll count[100002];
    rep(i, 100002){
        count[i] = 0;
    }
    rep(i, N){
        cin >> a[i];
        count[a[i]]++;
    }
    sort(a, a + N);

    ll counter;
    ll countMax = 0;
    ll check;
    rep(i, N){
        check = a[i];
        counter = 0;
        counter += count[check];
        if(check > 0){
            counter += count[check - 1];
        }
        counter += count[check + 1];//cout << "i: " << i << ", counter: " << counter << endl;
        if(counter > countMax){
            countMax = counter;
        }
    }

    cout << countMax << endl;
    
    return 0;
}