#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int n;
    cin >> n;
    string s,t;
    cin >> s >> t;

    int ans=2*n;
    bool a=true;
    for(int i=n; i>0; i--){
        a=true;
        for(int j=0; j<i; j++){
            if(s.at(n-i+j)!=t.at(j)){

                a=false;
                break;
            }
        }
        if(a){
            ans-=i;
            break;
        }
    }

    cout << ans << endl;
}