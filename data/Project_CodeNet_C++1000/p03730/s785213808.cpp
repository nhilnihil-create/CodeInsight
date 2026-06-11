#include <bits/stdc++.h>
using namespace std;

int main(){
    int a, b, c;

    cin >> a >> b >> c;

    int mod = c%b;  
    bool found = false;
    int times = 2*a;
    int i=2;
    while (i <= b  && !found){
        if(times%b==mod){
            found = true;
        }
        times=i*a;
        i++;
    }
    
    if(found){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
}