#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=3.141592653589793;

int main() {
    string s;
    cin>>s;
    int b=0;
    int ss=s.size();
    rep(i,ss-2){
        if (s[i]==s[i+1]){
            //string ans={s[i],s[i+1]};
            cout<<i+1<<" "<<i+2<<endl;
            b=1;
            break;
        }
        else if (s[i]==s[i+2]){
            //string ans={s[i],s[i+1],s[i+2]};
            //cout<<1<<endl;
            cout<<i+1<<" "<<i+3<<endl;
            b=1;
          break;
        }
    }
    if (b==0){
        if (s[ss-2]==s[ss-1]){
            //string ans={s[ss-2],s[ss-1]};
            
            cout<<ss-1<<" "<<ss<<endl;
        }
        else{
            cout<<-1<<" "<<-1<<endl;
        }
    
    }

    return 0;
}