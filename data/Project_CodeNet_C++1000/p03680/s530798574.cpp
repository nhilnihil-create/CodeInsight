#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> vec(n);
    rep(i,n){ cin >> vec[i];
        vec[i]--;
    }

    vector<bool> flag(n+2,false);
    int tmp = vec[0];

    rep(i,n-1){
        //cout << tmp << endl;
        if(!flag[tmp]){
            flag[tmp] = true;
            if(tmp == 1){
                cout << i+1 << endl;
                return 0;
            }
        }else{
            cout << -1 << endl;
            return 0;
        }
        tmp =  vec[tmp];
    }

    if(tmp == 1) cout << n << endl;
    else cout << -1 << endl;

    return 0;
}