#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,l,n) for(int i=(l);i<(n);i++)

template<class T>
using vt = vector<T>;
template<class T>
using vvt = vector<vector<T>>;

int edges[50][50];

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a <= c && c <= b) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;  
}

