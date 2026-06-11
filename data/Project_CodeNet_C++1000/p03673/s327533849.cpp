#include <iostream>
#include <deque>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n; cin >> n;
    deque<int> dq;
    for(int i = 1; i < n+1; ++i){
        int a; cin >> a;
        if(n%2 == i%2) dq.push_front(a);
        else dq.push_back(a);
    }
    for(int x : dq){
        cout << x << endl;
    }
    return 0;
}
//Saw the editorial