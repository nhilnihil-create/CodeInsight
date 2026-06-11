#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    long long a, b;
    cin >> a >> b;

    if (a*b <= 0){
        cout << "Zero" << endl;
        return 0;
    }

    if(a > 0 && b > 0){
        cout << "Positive" << endl;
        return 0;
    }

    if(a < 0 && b < 0){
        if((b-a+1)%2 == 0){
            cout << "Positive" << endl;
            return 0;
        }else{
            cout << "Negative" << endl;
            return 0;
        }
    }

    return 0;
}