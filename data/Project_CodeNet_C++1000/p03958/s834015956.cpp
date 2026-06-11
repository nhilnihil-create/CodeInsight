#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
const ll MOD = 1000000007;
const ld PI = acos(-1);  
const ld EPS = 0.0000000001;

int main(){
    int k, t;   cin >> k >> t;

    priority_queue<int> que;
    for(int i=0; i<t; i++){
        int x;  cin >> x;
        que.push(x);
    }
    while(1<que.size()){
        int x=que.top(); que.pop();
        int y=que.top(); que.pop();
        if(1<x) que.push(x-1);
        if(1<y) que.push(y-1);
    }

    cout << max(0, que.top()-1) << endl;
}