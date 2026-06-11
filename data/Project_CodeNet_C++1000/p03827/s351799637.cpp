#include <bits/stdc++.h>
using namespace std;

int main(void){
    
    int N,ans=0,x=0;
    string s;
    cin >> N >> s;

    for(int i=0;i<N;i++){
        if(s[i] == 'I'){
            x++;
        }
        else{
            x--;
        }
        
        if(ans < x) ans = x;
    }
    
    cout << ans << endl;
}