#include <bits/stdc++.h>          
using namespace std;               
 
int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++){
        cin >> a.at(i);
    }
    int A = 0;
    int k = 0;
    for(int i = 0; i < N; i++){
        A++;
        if(a.at(k) == 2) {
            break;
        }
        k = a.at(k) - 1;
    }
    if(A < N){
        cout << A << endl;
    }
    else{
        cout << -1 << endl;
    }
}
