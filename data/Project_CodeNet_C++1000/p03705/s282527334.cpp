#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;


const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    long long N,A,B; cin >> N >> A >> B;
    if(A > B) cout << 0 << endl;
    else if(A == B) cout << 1 << endl;
    else if(N < 2) cout << 0 << endl;
    else{
        cout << (B-A)*(N-2)+1 << endl;
    }
}
