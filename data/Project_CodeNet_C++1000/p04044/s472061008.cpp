#include<bits/stdc++.h>
using namespace std;
int main(){
    int N, L;
    cin >> N >> L;
    vector<string> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    for(int i = 0; i < N; i++){
        cout << A.at(i);
    }
    cout << endl;
    return 0;
}