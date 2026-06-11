#include <bits/stdc++.h>
using namespace std;
int main(){
    cin.tie(0); ios::sync_with_stdio(false);
    int a,b;cin >>a>>b;
    if((a<0&&b>0)||(a==0)||(b==0)){
        cout << "Zero";
        return 0;
    }
    else if(a>0){
        cout << "Positive";
        return 0;
    }
    else{
        if((b-a)%2==0){
            cout << "Negative";
            return 0;
        }
        else{
            cout << "Positive";
            return 0;
        }
    }
}


