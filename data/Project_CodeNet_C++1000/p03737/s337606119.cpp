#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(n) begin(n),end(n)
struct cww{cww(){ios::sync_with_stdio(false);cin.tie(0);}}star;
const long long INF = numeric_limits<long long>::max();
int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    
    cout << (char)((int)s1.at(0)-32)<< (char)((int)s2.at(0)-32)<< (char)((int)s3.at(0)-32)<<endl;
    return 0;
}