#include <bits/stdc++.h>

using namespace std;
#define repr(i,a,b) for (int i=a; i<b; i++)
#define rep(i,n) for (int i=0; i<  n; i++)
 
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const long long INF = 1LL << 60;

bool dp[100100];

int main () {
    string A,B;
    cin >> A >> B;

    if(A.size() > B.size())cout << "GREATER" << endl;
    else if(A.size() < B.size()) cout << "LESS" << endl;
    else{
        for(int i =0;i<A.size();i++){
            if(A[i]>B[i]){
                cout << "GREATER" << endl;
                return 0;;
            }
            else if(A[i]<B[i]){
                cout << "LESS" << endl;
                return 0;
            }
        }
        cout<< "EQUAL" << endl;

    }
    
}

