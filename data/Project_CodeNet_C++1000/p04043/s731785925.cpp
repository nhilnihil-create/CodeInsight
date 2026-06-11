#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin>>a>>b>>c;

    int aux_5 = 0;
    int aux_7 = 0;

    if(a==5) {
        aux_5++;
    } else if(a==7) {
        aux_7++;
    }
    
    if(b==5) {
        aux_5++;
    } else if(b==7) {
        aux_7++;
    }
    
    if(c==5) {
        aux_5++;
    } else if(c==7) {
        aux_7++;
    }

    if(aux_5==2 && aux_7==1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}