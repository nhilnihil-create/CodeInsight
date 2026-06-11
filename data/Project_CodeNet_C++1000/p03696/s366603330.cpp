#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG //これつけるとA[N]でもいいらしい
//for文のマクロ
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mp(a,b) make_pair(a,b)
#define big 1000000007
#define all(a) sort((a).begin(),(a).end()) //ソートのマクロ
#define Re(a) reverse((a).begin(),(a).end())
#define YN(a) if(a){cout<<"Yes"<<endl;}else cout<<"No"<<endl;//条件によってYes、Noを出力する
const int MOD=1000000007;
const double pi = 3.141592653589793;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    deque<char> d;
    int k=0;
    rep(i,n){
        if(s[i]=='('){
            k++;
        }
        else{
            k--;
        }
        d.push_back(s[i]);
        if(k<0){
            d.push_front('(');
            k++;
        }
    }
    while(k>0){
        d.push_back(')');
        k--;
    }
    int ds = d.size();
    rep(i,ds){
        cout<<d[i];
    }
  cout<<endl;
}