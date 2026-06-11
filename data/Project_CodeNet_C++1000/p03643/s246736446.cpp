#include<bits/stdc++.h>
using namespace std;

#define rep(i,n) for (int i = 0; i< (n); ++i)
#define vvec(m,n) vector<vector<int>> (int(m), vector<int>(n))
#define ALL(a) (a).begin(), (a).end()

using ll = long long;

int main(){
    int N;
    cin >> N;
    if(N < 10){
        cout << "ABC00" << N << endl;
    }else if(N < 100){
        cout << "ABC00" << N << endl;
    }else{
        cout << "ABC" << N << endl;
    }
}