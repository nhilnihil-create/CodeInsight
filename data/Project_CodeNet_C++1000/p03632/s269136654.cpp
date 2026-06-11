#include <bits/stdc++.h>
using namespace std;
using ll = long long; // ll は long long　と同じとする。(int64_t)
int main(){
    int A , B , C , D;
    cin >> A >> B >> C >> D;
    if(min(B , D) - max(A , C) >= 0){
        cout << min(B , D) - max(A , C) << endl;
    }
    else{
        cout << 0 << endl;
    }
}