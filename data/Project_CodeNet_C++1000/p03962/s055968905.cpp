#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int(i) = 0;(i) < (n); (i)++)
typedef long long ll;

int main(){
    int a,b,c;
    cin >> a >> b>>c;
    if(a == b && b == c){
        cout << "1" << endl;
    }else if(a == b){
        cout << "2" << endl;
    }else if(b == c){
        cout << "2" << endl;
    }else if(c == a){
        cout << "2" << endl;
    }else{
        cout << "3" << endl;
    }

}