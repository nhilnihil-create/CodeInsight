#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template <class T> inline bool chmin(T &a, T b) {if (a > b){a = b;return true;}return false;}
template <class T> inline bool chmax(T &a, T b) {if (a < b){a = b;return true;}return false;}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b;cin>>a>>b;
    if(a<=0 && 0<=b){
        cout<<"Zero"<<endl;
        return 0;
    }else{
        if(a<0 && b<0){
            if(a==b){
                cout<<"Positive"<<endl;
                return 0;
            }else if(abs(b-a)%2==0){
                cout<<"Negative"<<endl;
                return 0;
            }else{
                cout<<"Positive"<<endl;
                return 0;
            }
        }else{
            cout<<"Positive"<<endl;
            return 0;
        }
    }
    
}