#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (n); i++)
 
int main() {
    int N;
    cin >> N;
    set<int> se;
    int A;
    rep(i,N){
        cin >> A;
        se.insert(A);
    }
    if((N-se.size())%2){
        cout << se.size()-1 << endl;
    }else{
        cout << se.size() << endl;
    }

    return 0;
} 