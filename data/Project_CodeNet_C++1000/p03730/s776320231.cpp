#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rrep(i, n) for (int i = 1; i < (int)(n + 1); i++)
// vector<vector<int>> A(3, vector<int>(4));
int main() {
    int A,B,C;
    cin>>A>>B>>C;
    bool ans=false;
    rrep(i,B){
        if((A*i)%B==C){
            ans=true;
            break;
        }
    }
    if(ans==true){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}
