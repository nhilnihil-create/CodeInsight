#include <bits/stdc++.h>
using namespace std;
int main(void){

    set<int> b;
    int a;
    cin >> a;
    b.insert(a);
    cin >> a;
    b.insert(a);
    cin >> a;
    b.insert(a);
    /*
    if(c7 == 1 && c5 == 2 ){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    */
    
    cout << b.size() << endl;

    return 0; 
}
