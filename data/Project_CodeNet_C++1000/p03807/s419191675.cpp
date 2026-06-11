#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <map>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
    int n; cin >> n;
    vector<int> a(n);
    rep(i,n) cin >> a[i];
    vector<int> odd;
    rep(i,n){
        if(a[i]%2!=0){
            odd.push_back(a[i]);
        }
    }
    if(odd.size()%2!=0){
        cout << "NO" << endl;
        return 0;
    }else{
        cout << "YES" << endl;
    }
}