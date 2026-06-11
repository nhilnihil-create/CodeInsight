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


int main() {
    int N, x; cin >> N >> x;
    if(x==1 || x==2*N-1){
        cout << "No" << endl;
        return 0;
    }
    
    cout << "Yes" << endl;
    
    if(N==2){
        for(int i=0; i<3; i++) cout << i+1 << endl;
        return 0;
    }
    
    
    if(x==2){
        vector<int> V = {x+2, x, x-1, x+1};
        int on = 0;
        int cur = 0;
        vector<int> a;
        for(int i=0; i<2*N-1; i++){
            if(i+1<x-1 || i+1>x+2) a.push_back(i+1);
        }
        
        for(int i=0; i<2*N-1; i++){
            if(i<(2*N-2)/2-1 || i>(2*N-2)/2+2) cout << a[cur++] << endl;
            else cout << V[on++] << endl;
        }
        
        return 0;
    }
    
    vector<int> V = {x-1, x, x+1, x-2};
    int on = 0;
    int cur = 0;
    vector<int> a;
    for(int i=0; i<2*N-1; i++){
        if(i+1<x-2 || i+1>x+1) a.push_back(i+1);
    }
    for(int i=0; i<2*N-1; i++){
        if(i<(2*N-2)/2-1 || i>(2*N-2)/2+2) cout << a[cur++] << endl;
        else cout << V[on++] << endl;
    }
    
    
    return 0;
}
