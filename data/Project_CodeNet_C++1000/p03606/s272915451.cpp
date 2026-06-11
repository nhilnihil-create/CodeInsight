#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    int s = 0;
    int l ,r;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> l >> r;
        if(!(r == l)){
        s = s + (r - l) + 1;
        }
        if(r == l){
            s++;
        }
    }
    
    cout << s << endl;

}