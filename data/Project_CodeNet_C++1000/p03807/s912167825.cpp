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
    vector<int> even;
    vector<int> odd;
    rep(i,a.size()){
        if(a[i]%2==0) {
            even.push_back(a[i]);
        }else{
            odd.push_back(a[i]);
        }
    }
    int evenSum=0, oddSum=0;
    rep(i,even.size()) evenSum += even[i];
    rep(i,odd.size()) oddSum += odd[i];
    if((evenSum%2==0 && oddSum%2==0) || (evenSum%2!=0 && oddSum%2!=0)){
        cout << "YES" << endl;
        return 0;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}