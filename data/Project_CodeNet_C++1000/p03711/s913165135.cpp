#include<iostream>

using namespace std;

int main(){
    int n,m;

    cin >> n >> m;

    int g1;
    int g2;

    switch(n){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            g1 = 1;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            g1 = 2;
            break;
        }
        default: g1 = 3;

    }

    switch(m){
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12: {
            g2 = 1;
            break;
        }
        case 4:
        case 6:
        case 9:
        case 11: {
            g2 = 2;
            break;
        }
        default: g2 = 3;

    }

    if(g1 == g2) cout << "Yes";
    else cout << "No";

}