#include<bits/stdc++.h>
using namespace std;
int main(){
    int x, a, b;
    cin >> x >> a >> b;
    int da,db;
    da = abs(x-a);
    db = abs(x-b);
    if(da<db){
        cout << "A" << endl;
    }else{
        cout << "B" << endl;
    }
    return 0;
}


