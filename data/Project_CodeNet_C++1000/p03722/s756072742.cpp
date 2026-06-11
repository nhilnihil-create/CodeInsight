#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>
#include <iterator>
#include <iomanip>
#include <climits>
using namespace std; 
#define ll long long int


int main(){
    ll n, m;
    cin >> n >> m;
    vector<ll> a(m), b(m), c(m);
    for(int i = 0; i < m; ++i){
        cin >> a[i] >> b[i] >> c[i];
        a[i]--, b[i]--;
    }

    vector<ll> d(n, -1e18);
    vector<bool> used(n, false);
    d[0] = 0;
    used[0] = true;
    for(int i = 0; i <= 5 * m; ++i){
        for(int j = 0; j < m; ++j){
            if(used[a[j]]){
                if(!used[b[j]]){
                    used[b[j]] = true;
                    d[b[j]] = d[a[j]] + c[j];
                }
                else{
                    if(d[b[j]] < d[a[j]] + c[j]){
                        if(b[j] == n - 1 && i > 2 * n){
                            cout << "inf\n";
                            return 0;
                        }
                        d[b[j]] = d[a[j]] + c[j];
                    }
                }
            }
        }
    }
    cout << d[n - 1];
}
