#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main() {
    int N, L;
    string S[110];
    string iroha;
    cin >> N >> L;
    for(int i = 0; i < N; i++) 
        cin >> S[i];
    sort(S, S+N);
    for(int i = 0; i < N; i++)
        cout << S[i];
    cout << endl;
    return 0;
}