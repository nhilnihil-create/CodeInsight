#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    string a,b;
    cin>>a>>b;
    int ans = 0;
    if(a.size()>b.size()){
        ans = 1;
    }else if(a.size()<b.size()){
        ans = 2;
    }else{
        rep(i,a.size()){
            
            if(a[i]>b[i]){
                ans = 1;
                break;
            }else if(a[i]<b[i]){
                ans = 2;
                break;
            }
        }
    }
    
    if(ans==1){
        cout << "GREATER" << endl;
    }else if(ans==2){
        cout << "LESS" << endl;
    }else
        cout << "EQUAL" << endl;
    
    
    return 0;
}