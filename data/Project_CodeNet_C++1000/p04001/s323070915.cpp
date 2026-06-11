#include<iostream>
#include<string>
#include<algorithm>
#include<math.h>
#include<queue>
#include<vector>
#include<map>
#include<cstdlib>



using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

string s;

int main(){
    long long int ans=0;
    cin >> s;
    int n = s.size();
    long long int a;
    rep(i,(1<<(n-1))){
        a = 0;
        rep(j,n){
            a = a*10 + s[j] - '0';
            //cout << a << endl;
            if(j == n-1) break;
            else if((i>>j) & 1){
                ans += a; 
                a = 0;
            }
        }
        ans += a;
    }
    cout << ans << endl;
    return 0;
}