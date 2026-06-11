#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

    int N,A,sum=0; cin >> N;
    
    for(int i=0;i<N;i++){ cin >> A; if(A%2==1){sum++;} }
    
    if(sum %2 == 0) cout << "YES" << endl;
    else cout << "NO" << endl;
}