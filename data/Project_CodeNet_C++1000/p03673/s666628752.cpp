#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long ;

int main(){
    int n; cin >> n;
    vi a(n),b,b1,b2;
    for(int ix=0;ix<n;ix++){
        cin >> a.at(ix);
    }
    for(int ix=0;ix<n;ix++){
        if(ix%2 == 0) b1.push_back(a.at(ix));
        else b2.push_back(a.at(ix));
    }
    if(n%2 == 1){
        reverse(b1.begin(),b1.end());
        copy(b1.begin(),b1.end(),back_inserter(b));
        copy(b2.begin(),b2.end(),back_inserter(b));
    }
    else{
        reverse(b2.begin(),b2.end());
        copy(b2.begin(),b2.end(),back_inserter(b));
        copy(b1.begin(),b1.end(),back_inserter(b));
    }
    for(int ix=0;ix<n-1;ix++) cout << b.at(ix) << " " ;
    cout << b.at(n-1) << endl;
}