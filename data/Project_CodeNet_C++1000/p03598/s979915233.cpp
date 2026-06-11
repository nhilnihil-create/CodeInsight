#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, distance;
    distance = 0;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        int x;
        cin >> x;
        int distB = abs(x - k);  
        if(distB > x){
            distance += x * 2;
        }else{
            distance += distB*2;
        } 
    }
    cout << distance << endl;

}