#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
int main(void){
    // Your code here!
    int k, t;
    cin >> k >> t;
    priority_queue<P> pq;
    for(int i=0; i<t; i++){
        int c; cin >> c;
        pq.push(P(c, i));
    }
    int ans = 0;
    int prev = -1;
    
    while(!pq.empty()){
        int x = pq.top().first;
        int i = pq.top().second;
        pq.pop();
        
        // cout << x << " " << i << endl;
        if(i == prev){
            if (pq.size() > 0){
                int x2 = pq.top().first;
                int i2 = pq.top().second;    
                pq.pop();
                
                pq.push(P(x, i));
                prev = i2;
                if (x2 - 1 > 0) pq.push(P(x2 - 1, i2));
            }else{
                ans += x;
                break;
            }
        }else{
            if (x - 1 > 0) pq.push(P(x-1, i));
            prev = i;
        }
    }
    cout << ans << endl;
}
