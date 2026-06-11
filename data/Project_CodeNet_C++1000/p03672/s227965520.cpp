#include<bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i < (int)(n);i++)
#define all(x) (x).begin(),(x).end()
typedef long long ll;
int main(){
    string s;
    cin >> s;
    for(int i = s.size()/2-1;i > 0;i--){
        string t = s.substr(0,i);
        string u = s.substr(i,i);
        if(t == u){
            cout << i*2 << endl;
            return 0;
        }
    }
    return 0;
}