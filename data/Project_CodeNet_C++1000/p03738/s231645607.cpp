#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string a, b;
    cin >> a >> b;
    if(a.size() < b.size()){
        cout << "LESS" << endl;
    } else if(a.size() > b.size()){
        cout << "GREATER" << endl;
    } else {
        int i;
        for(i = 0; i < a.size(); i++){
            if(a[i] - '0' > b[i] - '0'){
                cout << "GREATER" << endl;
                return 0;
            } else if (a[i] - '0' < b[i] - '0'){
                cout << "LESS" << endl;
                return 0;
            }
        }
        if(i == a.size()){
            cout << "EQUAL" << endl;
        }
    }
    return 0;
}