#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define str(n) to_string(n)
#define int(w) stoi(w)
#define len(l) l.size()
#define append(l,i) l.push_back(i)
int main() {
    int n;
    cin>>n;
    vector<pair<int,int>> l;
    int b=1;
    int mod=pow(10,9)+7;
    if (n%2==1){
        rep(i,n/2+1){
          pair<int,int> d(i*2,0);
            append(l,d);
        }
        int n1;
        rep(i,n){
            cin>>n1;
            if (n1%2==1 || n1>n){
                b=0;
                break;
            }
            else{
                l.at(n1/2).second+=1;
            }
            
        }
        if (l.at(0).second!=1){
            b=0;
        }
        rep(i,n/2){
            if (l.at(i+1).second!=2){
                b=0;
                break;
            }
        }

    }
    else{
        rep(i,n/2){
          pair<int,int> d(i*2+1,0);
            append(l,d);
        }
        int n1;
        rep(i,n){
            cin>>n1;
            if (n1%2==0 || n1>n){
                b=0;
                break;
            }
            else{
                l.at(n1/2).second+=1;
            }
            
        }
        rep(i,n/2){
            if (l.at(i).second!=2){
                b=0;
                break;
            }
        }

    }
    if (b==1){
        long ans=1;
        rep(i,n/2){
            ans*=2;
            ans%=mod;
        }
        cout<<ans<<endl;
    }
    else{
        cout<<0<<endl;
    }

    return 0;
}
