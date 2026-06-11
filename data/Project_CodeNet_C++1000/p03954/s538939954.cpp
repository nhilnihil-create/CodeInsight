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
const int mod=1000000007,MAX=205,INF=1<<30;

int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    int N;cin>>N;
    vector<int> A(2*N-1);
    for(int i=0;i<2*N-1;i++) cin>>A[i];
    
    int left=1,right=2*N-1;
    while(right-left>1){
        int mid=(left+right)/2;
        
        vector<int> B(2*N-1);
        for(int i=0;i<2*N-1;i++) if(A[i]>=mid) B[i]=1;
        
        bool ok=false;
        
        int s=N-1,t=N-1;
        
        if(B[s-1]+B[s]==2||B[s]+B[s+1]==2) ok=true;
        else if(B[s]||B[s-1]+B[s+1]==2){
            if(B[s]){
                s-=2;
                t+=2;
            }else{
                s--;
                t++;
            }
            
            while(s>=0){
                if(s==0&&B[s]&&B[t]){
                    ok=true;
                    break;
                }
                
                if(!B[s]||!B[t]) break;
                
                if(B[s-1]||B[t+1]){
                    ok=true;
                    break;
                }
                
                s-=2;
                t+=2;
            }
        }
        
        if(ok) left=mid;
        else right=mid;
    }
    
    cout<<left<<endl;
    
}
