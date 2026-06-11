#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main(void){
    int x,a,b;
    cin >> x >> a >> b;
    
    int dist1 = abs(x - a);
    int dist2 = abs(x - b);
    
    if (dist1 < dist2){
        cout << 'A' << endl;
        return 0;
    }
    else{
        cout << 'B' <<endl;
        return 0;
    }
}
