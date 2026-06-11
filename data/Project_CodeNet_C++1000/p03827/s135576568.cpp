#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    int x, N;
    x = 0;
    string S;
    cin >> N >> S;
    int count = N;
    vector<int> num(N+1);
    num.at(0) = x;
    for (int i = 0; i < count; i++)
    {
        if(S.at(i) == 'I'){
            x++;
            num.at(i+1) = x;
        }
        else if(S.at(i) == 'D' ){
            x--;
            num.at(i+1) = x;
        }
    }
    sort(num.begin(), num.end());
    cout << num.at(N) << endl;
    
    
    
}
