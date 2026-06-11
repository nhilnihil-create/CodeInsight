#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int tmp1, tmp2;
    tmp1 = b-a;
    tmp2 = c-b;
    if(tmp1==tmp2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}


