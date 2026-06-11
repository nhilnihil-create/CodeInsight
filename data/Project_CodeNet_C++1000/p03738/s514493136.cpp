#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string A, B;
    cin >> A;
    cin >> B;
    string ans = " ";
    if(A.size() > B.size()) {
        ans = "GREATER";
    } else if(A.size() < B.size()) {
        ans = "LESS";
    } else {
        for(int i = 0; i < A.size(); i++) {
            int a = int(A[i]);
            int b = int(B[i]);
            if(a > b) {
                ans = "GREATER";
                break;
            } else if(a < b) {
                ans = "LESS";
                break;
            } 
        }
        if(ans == " ") {
            ans = "EQUAL";
        }
    }
    cout << ans << endl;
    return 0;
}