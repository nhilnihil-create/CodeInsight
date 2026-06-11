#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return true; } return false; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return true; } return false; }
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
#define mp make_pair
#define si(x) int(x.size())
const int mod=998244353,MAX=100005;
const ll INF=1LL<<60;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N,M;cin>>N>>M;
    vector<int> A,B;
    for(int i=0;i<M;i++){
        int a;cin>>a;
        if(a&1){
            B.push_back(a);
        }else{
            A.push_back(a);
        }
    }
    
    if(si(B)==0){
        for(int i=0;i<M;i++) cout<<A[i]<<" ";
        cout<<endl;
        cout<<M+1<<endl;
        for(int i=0;i<M;i++){
            if(i==0) cout<<A[i]-1<<" ";
            else cout<<A[i]<<" ";
        }
        cout<<1<<endl;
    }else if(si(B)==1){
        if(si(A)==0){
            if(N==1){
                cout<<1<<endl;
                cout<<1<<endl;
                cout<<1<<endl;
            }else{
                cout<<N<<endl;
                cout<<2<<endl;
                cout<<N-1<<" "<<1<<endl;
            }
        }else{
            for(int i=0;i<si(A);i++) cout<<A[i]<<" ";
            cout<<B[0]<<endl;
            cout<<M<<endl;
            for(int i=0;i<si(A);i++){
                if(i==0) cout<<A[i]-1<<" ";
                else cout<<A[i]<<" ";
            }
            cout<<B[0]+1<<endl;
        }
    }else if(si(B)==2){
        sort(all(B));
        if(si(A)==0){
            if(N==2){
                cout<<B[0]<<" "<<B[1]<<endl;
                cout<<1<<endl;
                cout<<N<<endl;
            }else{
                cout<<B[0]<<" "<<B[1]<<endl;
                cout<<2<<endl;
                cout<<B[1]-1<<" "<<B[0]+1<<endl;
            }
        }else{
            cout<<B[0]<<" ";
            for(int i=0;i<si(A);i++) cout<<A[i]<<" ";
            cout<<B[1]<<endl;
            
            vector<int> ans;
            if(B[0]-1) ans.push_back(B[0]-1);
            for(int i=0;i<si(A);i++) ans.push_back(A[i]);
            ans.push_back(2);
            if(B[1]-1) ans.push_back(B[1]-1);
            
            cout<<si(ans)<<endl;
            for(int a:ans) cout<<a<<" ";
            cout<<endl;
        }
    }else{
        cout<<"Impossible"<<endl;
    }
}
