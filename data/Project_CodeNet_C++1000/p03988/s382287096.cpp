#include <bits/stdc++.h>
using namespace std;

multiset<int> A;

void fail(){
    cout << "Impossible" << endl;
    exit(0);
}


void solve(long long N, vector<long long> a){
    for( auto i : a) A.insert(i);

    int len = *A.rbegin();

    for(int i = 0 ; i <= len ; i++){
        auto it = A.find(max(len - i, i));
        if( it == A.end() ) fail();
        A.erase(it);
    }

    if( A.count((len+1) / 2) > 0 ){
        fail();
    }
    cout << "Possible" << endl;

}

int main(){    
    long long N;
    scanf("%lld",&N);
    vector<long long> a(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&a[i]);
    }
    solve(N, a);
    return 0;
}

