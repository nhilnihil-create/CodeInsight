#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define str(n) to_string(n)
#define int(w) stoi(w)
#define len(l) l.size()
#define append(l,i) l.push_back(i)
int main() {
    int n;
    cin>>n;
    int t,a,t1,a1;
    long long num;
    cin>>t>>a;
    long long tot=t+a;
    long long num1=1;
    rep(i,n-1){
        cin>>t1>>a1;
        num=max(((num1*t-1)/t1)+1,((num1*a-1)/a1)+1);
        tot=num*(a1+t1);
        num1=num;
        a=a1;
        t=t1;
    }
    cout<<tot<<endl;
    

    return 0;}