#include <iostream>
#include <set>
using namespace std; 

int main(){
    int x, y;
    cin >> x >> y;

    set<int>a{1,3,5,7,8,10,12};
    set<int>b{4,6,9,11};
    set<int>c{2};

    const bool x_is_in_a = a.find(x) != a.end();
    const bool x_is_in_b = b.find(x) != b.end();
    const bool x_is_in_c = c.find(x) != c.end();
    const bool y_is_in_a = a.find(y) != a.end();
    const bool y_is_in_b = b.find(y) != b.end();
    const bool y_is_in_c = c.find(y) != c.end();

    if( x_is_in_a == y_is_in_a && x_is_in_a == 1 ){
        cout << "Yes" << endl;
        return 0;
    } else if( x_is_in_b == y_is_in_b && x_is_in_b == 1 ) {
        cout << "Yes" << endl;
        return 0;
    } else if( x_is_in_c == y_is_in_c && x_is_in_c == 1 ) {
        cout << "Yes" << endl;
        return 0;
    } else {
        cout << "No" << endl;
        return 0;
    }
    
}