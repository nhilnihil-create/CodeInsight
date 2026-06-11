#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main(){
    vector<vector<long long int>> v;
    int n;
    long long int k;
    cin >> n >> k;
    rep(i,n){
        long long int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    sort(v.begin(),v.end());
    vector<long long int> total_v;
    
    long long int total = 0;
    for(auto w:v){
        total+=(long long int)w[1];
        total_v.push_back(total);
    }
    auto itr = lower_bound(total_v.begin(),total_v.end(),k);
    int p = distance(total_v.begin(),itr);
    cout << v[p][0] << endl;
}