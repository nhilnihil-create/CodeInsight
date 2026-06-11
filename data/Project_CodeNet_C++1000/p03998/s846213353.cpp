#include <bits/stdc++.h>
using namespace std;

void solve(){
    string A, B, C;
    cin >> A >> B >> C;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    reverse(C.begin(), C.end());
    char curr = 'a';
    while(1){
        if(curr == 'a'){
            if(A.size() == 0){
                cout << "A\n";
                return;
            }
            curr = A.back();
            A.pop_back();
        } else if(curr == 'b'){
            if(B.size() == 0){
                cout << "B\n";
                return;
            }
            curr = B.back();
            B.pop_back();
        } else{
            if(C.size() == 0){
                cout << "C\n";
                return;
            }
            curr = C.back();
            C.pop_back();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool multitest = false;
   // multitest = true;
    if(multitest){
        int t; cin >> t;
        while(t--)
            solve();
    }
    else
        solve();
}




