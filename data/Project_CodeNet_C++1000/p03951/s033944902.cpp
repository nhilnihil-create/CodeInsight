#include <bits/stdc++.h>
#include <string.h>
//s#define rep(i, n) for (int i = 0; i < (n); i++)
#define MAX 10000

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define rep(i,a,n) for(int i=a; i<n; i++)
#define r0 return 0
#define INF (int)1e15


int main(){

 int n;
 cin>>n;

 string a,b;
 cin>>a>>b;

 long long ans=0;

 if(a == b){
    cout<<n<<endl;
   return 0;
}
else{

    int cnt=0;

    for(int i=0;i<n;i++){
        if(a.substr(n-1-i) == b.substr(0,i+1))
            cnt = i+1;
    }

    ans = n*2 - cnt;
     cout<<ans<<endl;
}


 return 0;
}
