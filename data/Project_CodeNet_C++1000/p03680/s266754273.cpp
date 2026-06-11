#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
const ll mod = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
#define _GLIBCXX_DEBUG 
 int main(){
     int n;
     cin>>n;
     vector<int> light(n);
     rep(i,n){
         cin>>light[i];
     }

     vector<int> a(n);
     int memory=1;

    rep(i,n){
        a[i]=light[memory-1];
        memory=a[i];
    }

    int count=0;
    rep(i,n){
        if(a[i]==2) {
            count+=i+1;
            break;
        }
        else continue;
    }
    if(count>0) cout<<count<<endl;
    else cout<<-1<<endl;
 }
