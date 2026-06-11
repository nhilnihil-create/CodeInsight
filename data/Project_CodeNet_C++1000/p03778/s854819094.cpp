#include<bits/stdc++.h>
using namespace std;

int main(){
    int w, a, b;
    cin >> w >> a >> b;
    if(a <= b){
        for(int i = 0;;i++){
            if(b <= a + w + i && a + w + i <= b + w){
                cout << i << endl;
                return 0;
            }
        }
    }
    else{
        for(int i = 0;;i++){
            if(a <= b + w + i && b + w + i <= a + w){
                cout << i << endl;
                return 0;
            }
        }
    }
}