#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <array>
#include <bitset>
using namespace std;

typedef long long ll;
const ll mod=1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define Rep(i,n) for(int i=1;i<n+1;i++)

void print(vector<int> vec){
    while(!vec.empty()){
        if(vec.front()==1) cout<<"S";
        else cout<<"W";
        vec.erase(vec.begin());
    }
}

int main(){
    int N;
    string s;
    cin>>N>>s;
    vector<int> vec,ans;
    rep(i,s.size()){
        if(s[i]=='o') vec.push_back(1);
        else vec.push_back(-1);
    }

    int a1,a2;
    int a_,b_,c;
    rep(i,2){
        a1=2*i-1;
        rep(j,2){
            a2=2*j-1;
            ans.clear();
            ans.push_back(a1);
            ans.push_back(a2);
            a_=a1;b_=a2;
            rep(k,N-2){
                c=a_*b_*vec[k+1];
                a_=b_;
                b_=c;
                ans.push_back(c);
            }
            if(a_*c*a1==vec[N-1] && c*a1*a2==vec[0]){
                print(ans);
                return 0;
            }
        }
    }
    cout<<-1<<endl;
    return 0;
}