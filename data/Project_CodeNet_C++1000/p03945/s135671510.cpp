#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;

int main() {
    string S; cin >> S;
    int count =0;
    for(int i=1;i<S.size();i++){
        if(S[i-1]!=S[i])count++;
    }
    cout << count << endl;
}

