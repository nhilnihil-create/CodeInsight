#include <bits/stdc++.h>
using namespace std;
int main(void){
    
    /*
    int a, b, c;
    cin >> a >> b >> c ;
    */
    
    vector<int> a(3);
    cin >> a.at(0) >> a.at(1) >> a.at(2) ;
    
    sort(a.begin(), a.end());
    
    /*
    if( b >= c ){
        cout << "delicious" << endl;
    } else if ( b < c && c <= a + b){
        cout << "safe" << endl;
    } else {
        cout << "dangerous" << endl;
    }
    */
    
    cout << a.at(0) + a.at(1) << endl;

    return 0; 
}
