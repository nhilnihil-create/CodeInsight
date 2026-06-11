#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
using ll = long long;
#define int ll

signed main(){
    int N; cin >> N;
    vector<int>A(N);
    for(auto & e : A) cin >> e;
    int sum = A.front() - 1;
    int crt = 2;
    for(int i = 1; i < A.size(); ++i){
        if(crt > A[i])continue;
        if(crt == A[i]){++crt; continue;}
        int mod = A[i] % crt;
        int div = A[i] / crt;
        sum += div - (mod == 0);
        crt = max(crt,(mod != 0 ? 1 : crt));
    }
    cout << sum << endl;
}
