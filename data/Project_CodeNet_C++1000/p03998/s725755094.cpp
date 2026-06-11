#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,n) for(int i=s;i<n;i++)
#define NUM 2520
#define INF (1LL<<50)
#define DEBUG 0
#define mp(a,b) make_pair(a,b)
#define SORT(V) sort(V.begin(),V.end())
#define PI (3.141592653589794)
#define TO_STRING(VariableName) # VariableName
#define LOG(x) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<endl;
#define LOG2(x,y) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<endl;
#define LOG3(x,y,z) if(DEBUG)cout<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;
#define LOG4(w,x,y,z) if(DEBUG)cout<<TO_STRING(w)<<"="<<w<<" "<<TO_STRING(x)<<"="<<x<<" "<<TO_STRING(y)<<"="<<y<<" "<<TO_STRING(z)<<"="<<z<<endl;

template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T& a, const T& b) { if (b < a) { a = b; return 1; } return 0; }

lli nex(char c){
    return c-'a';
}

void func(std::string S_A, std::string S_B, std::string S_C){

    lli aCnt=0,bCnt=0,cCnt=0;
    lli now = 0;
    while(1){
        lli nex;
        LOG(now);
        if(now==0){
            
            if(aCnt >= S_A.size()){
                cout<<'A'<<endl;
                return;
            }
            nex = (S_A[aCnt]-'a');
            aCnt++;
        }
        else if(now==1){
            
            if(bCnt >= S_B.size()){
                cout<<'B'<<endl;
                return;
            }
            nex = (S_B[bCnt]-'a');
            bCnt++;
        }
        else{
            
            if(cCnt >= S_C.size()){
                cout<<'C'<<endl;
                return;
            }
            nex = (S_C[cCnt]-'a');
            cCnt++;
        }
        now = nex;
    }

}

int main(){
    // cout << fixed << setprecision(5);

    std::string S_A;
    std::cin >> S_A;
    std::string S_B;
    std::cin >> S_B;
    std::string S_C;
    std::cin >> S_C;
    func(S_A, S_B, S_C);
    return 0;
}
