#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define per(i,n) for (int i = (n)-1; i >=0; --i)
using namespace std;
using ll = long long;
using vi = vector<int>;
using vv = vector<vi>;

int main(){
    int n;cin>>n;
    vi a(n);
    rep(i,n)cin>>a[i];
    
    if(n==1){
        cout << 1 << endl;
        return 0;
    }
    
    bool start = true;
    int ans = 0, dir = 0, bdir = 0;
    
    vv b(1);
    vi c,o;
    
    for(int i=0; i<n; i++){
        
        if(b.back().size()==0){
            b.back().push_back(a[i]);
            
        }else if(b.back().size()==1){
            if(a[i]>b.back().back())
                c.push_back(1);
            if(a[i]<b.back().back())
                c.push_back(-1);
            if(a[i]==b.back().back())
                c.push_back(0);
            
            b.back().push_back(a[i]);
            
        }else{
            if(a[i]>b.back().back() && c.back()==-1){
                ans++;
                b.push_back(o);
                b.back().push_back(a[i]);
            }else if(a[i]<b.back().back() && c.back()==1){
                ans++;
                b.push_back(o);
                b.back().push_back(a[i]);
            }else{
                if(c.back()==0){
                    if(a[i]>b.back().back())
                        c.back()=1;
                    if(a[i]<b.back().back())
                        c.back()=-1;
                    if(a[i]==b.back().back())
                        c.back()=0;
                }
                b.back().push_back(a[i]);
            }
        }
        
    }
    /*
    rep(i,b.size()){
        rep(j,b[i].size()){
            cout << b[i][j] << " ";
        }
        cout << endl;
    }
    */
    cout << b.size() << endl;
    
    return 0;
}