#include <iostream>
#include <vector>
#include <utility>
#include <string>
#include <map>
#include <algorithm>
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n){
        cin >> a[i];
    }
    sort(a.rbegin(),a.rend());
    map<int,int>mp;
    const int d = a[0];
    //d = 2, 2,1,2
    //d = 4, 1--2--3--4--5, 4,3,2,3,4
    //d = 5, 1--2--3--4--5--6, 5,4,3,3,4,5
    rep(i,n){
        mp[a[i]]++;
    }
    for(int i = d; i >= d/2+1; i--){
        mp[i]-=2;
    }
    if(d%2==0){
        mp[d/2]--;
    }
    for(auto &x:mp){
        if(x.second < 0){
            cout << "Impossible" << endl;
            return 0;
        }else if(x.second > 0){
            if(x.first <= (d+1)/2){
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }
    cout << "Possible" << endl;
    return 0;
}