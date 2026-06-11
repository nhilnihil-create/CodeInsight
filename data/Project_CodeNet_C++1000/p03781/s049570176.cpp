#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll factorial(int n){
    if(n==1)return 1;
    else return n + factorial(n-1); 
}

int main(){
    int x;
    cin >> x;
    //cout << factorial(x) << endl;
    for(int i=1;;i++){
        if(factorial(i)>=x){cout << i << endl;break;}
    }
    return 0;
}