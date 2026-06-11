    #include <bits/stdc++.h>
    using namespace std;
     
    typedef long long ll;
     
    #define rep(i, n) for (int i = 0; i < (int)(n); i++)
     
    int main() { 
        string A,B;
        cin >> A;
        cin >> B;
        if (A.length() == B.length()) {
            rep(i, A.length()){
                if (A[i] < B[i]) {
                    cout << "LESS" << "\n";
                    return 0;
                } else if (A[i] > B[i]) {
                    cout << "GREATER" << "\n";
                    return 0;
                } else {
                    continue;
                }
            }
        } else {
            if (A.length() < B.length()) {
                cout << "LESS" << "\n";
                return 0;
            } else {
                cout << "GREATER" << "\n";
                return 0;
            }
        }
        cout << "EQUAL" << "\n";
     
        return 0;
    }