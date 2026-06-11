#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    string N, M;
    cin >> N >> M;
    rep(i,0,M.size())cout<<N[i]<<M[i];
    if(N.size()>M.size())cout<<N[N.size()-1]<<endl;
    return 0;
}