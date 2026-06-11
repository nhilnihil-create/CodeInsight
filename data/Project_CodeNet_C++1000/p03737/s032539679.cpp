#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,N) for(int i=0; i<N; i++){ ;
int main() {
    string A,B,C;
    cin>>A>>B>>C;
    char p=A.at(0);
    char r=B.at(0);
    char q=C.at(0);
   p=toupper(p);
    q=toupper(q);
    r=toupper(r);
    cout<<p<<r<<q<<endl;
}