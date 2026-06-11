#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    
    int n ,m;
    cin >> n  >> m;
    int a[m] ,b[m],c[n] ,d[n];
    for(int i = 0 ; i < m ; i++){
        cin >> a[i] >> b[i];
    }
    
    for(int v = 0; v < n ; v++){
        d[v] = 0;
    }
    for(int j = 0 ; j < n ; j++){
        for(int t = 0;t < m;t++){
            if(a[t] == j+1 || b[t] == j+1){
                d[j] += 1;
            }    
        }
    }
    
    for(int y = 0;y < n;y++){
        cout << d[y] << endl;
    }
    
    
    
}