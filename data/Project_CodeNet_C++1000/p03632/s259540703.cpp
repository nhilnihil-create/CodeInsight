#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG 

int main(){
    int A,B,C,D;
    cin>>A>>B>>C>>D;
    vector<int> srt={A,B,C,D};
    sort(srt.begin(),srt.end());
    int count=0;
    if(B<=C||A>=D) cout<<count<<endl;
    else{
        count=srt[2]-srt[1];
        cout<<count<<endl;
    }
}