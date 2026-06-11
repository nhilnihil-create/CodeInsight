#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using vi=vector<int>;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
template<typename T> void ndarray(vector<T> &vec, int len) { vec.resize(len); }
template<typename T, typename... Args> void ndarray(vector<T> &vec, int len, Args... args) { vec.resize(len); for (auto &v : vec) ndarray(v, args...); }

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string sa,sb,sc;
    cin >> sa >> sb >> sc;
    int a=sa.size();
    int b=sb.size();
    int c=sc.size();
    int aa=0,bb=0,cc=0,x=0;
    while(1){
        if(x==0){
            if(aa==a){
                cout << "A" << "\n";
                return 0;
            }
            x=sa[aa] - 'a';
            ++aa;
        }else if(x==1){
            if(bb==b){
                cout << "B" << "\n";
                return 0;
            }
            x=sb[bb] - 'a';
            ++bb;
        }else{
            if(cc==c){
                cout << "C" << "\n";
                return 0;
            }
            x=sc[cc] - 'a';
            ++cc;
        }
    }
}   