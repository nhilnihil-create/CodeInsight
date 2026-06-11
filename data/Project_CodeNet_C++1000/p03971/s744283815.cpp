#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,x) for(int i=0;i<x;i++)
#define put(ans)    cout << ans << endl;
#define reverse(s) reverse(s.begin(),s.end())

int main(){
    int n,a,b,sum(1),f(1);
    cin >> n >> a >> b;
    string s;   cin >> s;


    rep(i,n){
        if(s[i]!='c'){
            if(sum<=(a+b)){
                if(s[i]=='a'){
                    cout << "Yes" << endl;
                    sum++;
                }else if(f<=b){
                    cout << "Yes" << endl;
                    sum++;
                    f++;
                }else{
                    cout << "No" << endl;
                }
            }else{
                cout << "No" << endl;
            }
        }else{
            cout << "No" << endl;
        }
    }
 
    return 0;
}