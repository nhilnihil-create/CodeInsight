#include <bits/stdc++.h>
using namespace std;

map<int , int> nodes;

signed main(){
    int n , a , node[2] = {};
    
    cin >> n;
    for(int i=0 ;i<n ;i++ ){
        cin >> a;
        nodes[a]++;
        if(nodes[a] == 4){
            node[0] = max(node[0] , a);
            node[1] = max(node[1] , a);
        } else if(nodes[a] == 2){
            if(node[0] > node[1]){
                node[1] = max(node[1] , a); 
            } else {
                node[0] = max(node[0] , a);
            }
        }
    }
    
    cout << (long long)node[0] * node[1] << endl;
    return(0);
}