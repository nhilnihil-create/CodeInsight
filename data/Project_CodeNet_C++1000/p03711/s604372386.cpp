#include <bits/stdc++.h>

using namespace std;

int judge(int i){
    if (i == 2){
        return 3;
    }else if (i == 4 || i == 6 || i == 9 || i == 11){
        return 2;
    }else if ( i == 1 || i == 3 || i == 5 || i == 7 || i == 8 || i == 10 || i == 13){
        return 1;
    }
}
int main() {
    int x, y;
    cin >> x >> y;

    if (judge(x) == judge(y)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

}