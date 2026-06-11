#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
    
int main(){
    int n, in;
    int n0 = 0;
    int n1 = 0;
    int n2 = 0;
    cin >> n;
    rep(i, n){
        cin >> in;
        if(in%4 == 0){
            n2++;
        }else if(in%2 == 0){
            n1++;
        }else{
            n0++;
        }
    }
    if(n1 == 0) n2++;
    if(n2 >= n0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}