#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <map>
#include <unordered_map>
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
#define repr(e,x) for(auto& e:x)
using namespace std;
typedef long long ll;
typedef long double ld;

int N;
string S;

int main(){
    cin>>N>>S;

    int l=0, r=0;
    rep(i,N){
        if(S[i]=='(') l++;
        else if(l>0) l--;
        else r++;
    }

    string ans;
    rep(i,r) ans+='(';
    ans+=S;
    rep(i,l) ans+=')';

    cout<<ans<<endl;
}