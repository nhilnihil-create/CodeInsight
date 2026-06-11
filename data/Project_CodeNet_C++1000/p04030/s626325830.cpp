////////////////////////////////////
///     Please Give Me AC!!!     ///
////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main(){
    string s;
    cin>> s;
    int N = s.size();
    string ans;

    rep(i, N){
        if(s[i] == '0'){
            ans.push_back('0');
        }else if(s[i] == '1'){
            ans.push_back('1');
        }else{
            if(!ans.empty()){
                ans.pop_back();
            }
        }
    }
    cout<< ans << endl;
}