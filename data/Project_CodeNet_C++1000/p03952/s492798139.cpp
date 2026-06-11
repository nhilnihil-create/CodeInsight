#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    ll N,x;
    cin >> N >> x;
    if(x == 1 || x == 2 * N - 1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    queue<ll> q1 = queue<ll>();
    queue<ll> q2 = queue<ll>();
    if(x == 2 * N - 2){
        q2.push(x-1);
        q2.push(x+1);
        q2.push(x);
        q2.push(x-2);
        int i = 1;
        while(i <= 2 * N - 1) {
            if(i < x - 2 || x + 1 < i){
                q1.push(i);
            }
            i++;
        }
    }else{
        q2.push(x+1);
        q2.push(x-1);
        q2.push(x);
        q2.push(x+2);
        int i = 1;
        while(i <= 2 * N - 1) {
            if(i < x - 1 || x + 2 < i){
                q1.push(i);
            }
            i++;
        }
    }
    for (int i = 1; i <= 2 * N - 1; ++i) {
           if( N - 2  <= i && i <= N + 1){
                cout << q2.front() << " ";
                q2.pop();
            }else{
                cout << q1.front() << " ";
                q1.pop();
            }
    }

}
