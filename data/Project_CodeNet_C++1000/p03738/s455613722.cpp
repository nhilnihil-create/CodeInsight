#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main() {
    string A , B;
    cin >> A >> B;
    int a = A.size();
    int b = B.size();
    if(a > b){
        cout << "GREATER" << endl;
    }
    else if(b > a){
        cout << "LESS" << endl;
    }
    else if(A == B){
        cout << "EQUAL" << endl;
    }
    else if(A > B){
        cout << "GREATER" << endl;
    }
    else{
        cout << "LESS" << endl;
    }
}