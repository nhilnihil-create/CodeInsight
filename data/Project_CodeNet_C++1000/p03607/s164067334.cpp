#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int N,A;
    set<int> s{};
    cin >> N;
    
    for(int i=0;i<N;i++){
        cin >> A;
        if(s.count(A) == 0) s.insert(A);
        else s.erase(A);
    }
    cout << s.size() << endl;
}