#include<iostream>
#include<algorithm>
using namespace std;
const int N = 105;
string S[N];
bool cmp(string a, string b) {
    return a < b;
}
int main() {
    int n,l;
    cin >> n >> l;
    for(int i = 1; i <= n; ++i) {
        cin >> S[i];
    }
    sort(S+1,S+1+n,cmp);
    for(int i = 1; i <= n; ++i)
        cout << S[i];
    cout << '\n';
return 0;
}