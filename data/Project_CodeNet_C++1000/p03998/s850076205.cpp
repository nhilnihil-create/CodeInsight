#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
#define FOR(i,n,j) for(int i=(j);i<(n);++i)
#define ssort(n) sort((n).begin(),(n).end())

using ll=long long;
using ld=long double;
typedef pair<int,int> P;
#define INF 10101010

int main()
{
    string A,B,C;
    cin >> A;
    cin >> B;
    cin >> C;
    queue<char> A_q,B_q,C_q;

    rep(i,A.size()){
        A_q.push(A[i]);
    }
    rep(i,B.size()){
        B_q.push(B[i]);
    }
    rep(i,C.size()){
        C_q.push(C[i]);
    }
    char c='a';
    while(c!='e'){
        
        switch(c){
            case 'a':
                    
                if(A_q.empty()){
                    cout << 'A' << endl;
                    c='e';
                    break;
                }
                c=A_q.front();
                A_q.pop();

                break;
            case 'b':
                if(B_q.empty()){
                    cout << 'B' << endl;
                    c='e';
                    break;
                }
                c=B_q.front();
                B_q.pop();

                break;
            case 'c':
                if(C_q.empty()){
                    cout << 'C' << endl;
                    c='e';
                    break;
                }
                c=C_q.front();
                C_q.pop();

                break;
            defalut:
                break;
        }
    }
}