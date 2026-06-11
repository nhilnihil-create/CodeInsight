#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i,a,b) for (int i = (a); i < (b); i++ )
typedef pair<int,int> P;
typedef long long ll;
const int INF = 100000000;
const double PI=3.14159265358979323846;

int main (){
    string S;
    cin >> S;

    int a[S.size()];
    a[0] = 0;
    
    rep(i,1,S.size()) {
        if (S[i]==S[i-1]) {
            a[i]=a[i-1];
        }
        else {
            a[i] = a[i-1]+1;
        }
    }
    cout << a[S.size()-1] << endl;
}



