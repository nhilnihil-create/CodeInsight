#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
using ll = long long;
using p = pair<int,int>;
int main(int argc, const char * argv[]) {



    cin.tie(0);
    ios::sync_with_stdio(false);

    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    if(s1[s1.size()-1]==s2[0]&&s2[s2.size()-1]==s3[0])cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;
}
