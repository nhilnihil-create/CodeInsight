#include <iostream>
#include<vector>
#include <map>
using namespace std;


int main(void){
    int n;
    long long k;
    cin >> n >> k;
    map<int,long long> m;
    
    for (int i = 0; i < n; i++) {
        int a,b;
        cin >> a >> b;
        m[a] += b;
    }
    
    long long sum = 0;
    for(auto p : m) {
        sum += p.second;
        if(sum >= k) {
            cout << p.first << endl;
            break;
        }
    }
}
