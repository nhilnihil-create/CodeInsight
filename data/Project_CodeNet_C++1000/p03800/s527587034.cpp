#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,n) for(long long i=0;i<n;++i)
#define REPP(i,m,n) for(long long i=m;i<n;++i)
#define rep(i,n) for(long long i = n-1;i>=0;--i)
#define repp(i,n,m) for(long long i = n-1; i >= m; --i)
#define ALL(N) (N.begin(),N.end())
#define de cout << "line : " << __LINE__ << " debug" << endl;
#define pb push_back
#define pq priority_queue
#define Dcout(N) cout << setprecision(20) << N << endl
constexpr ll INF = 2147483647;
constexpr long long INFF = 9223372036854775807;

int N;
string S;
vector<int> V;

void ANS(int A){
    V.pb(A);
    REPP(i,1,N){
        int B;
        if(S[i-1] == 'o' && S[i] == 'x'){
            if(A == 1) B = 4;
            else if(A == 2) B = 6;
            else if(A == 7) B = 3;
            else if(A == 8) B = 5;
        }
        else if(S[i-1] == 'o' && S[i] == 'o'){
            if(A == 1) B = 1;
            else if(A == 2) B = 8;
            else if(A == 7) B = 2;
            else if(A == 8) B = 7;
        }
        else if(S[i-1] == 'x' && S[i] == 'o'){
            if(A == 5) B = 7;
            else if(A == 6) B = 2;
            else if(A == 3) B = 1;
            else if(A == 4) B = 8;
        }
        else{
            if(A == 5) B = 5;
            else if(A == 6) B = 3;
            else if(A == 3) B = 4;
            else if(A == 4) B = 6;
        }
        V.pb(B);
        A = B;
    }

    REP(i,V.size()){
        if(V[i] == 1 || V[i] == 2 || V[i] == 3 || V[i] == 4){
            cout << 'S';
        }
        else cout << 'W';
    }
    cout << endl;
    exit(0);
}

bool solve(int X,int A,int Fi){
    if(X == N){
      //cout << A << ' ' << Fi << endl;
        //成り立つかどうかと逆算パートへ
        if(A == Fi) return 1;
        else return 0;
    }
    int B;
    if(S[X] == 'o' && S[X+1] == 'x'){
        if(A == 1) B = 4;
        else if(A == 2) B = 6;
        else if(A == 7) B = 3;
        else if(A == 8) B = 5;
        solve(X+1,B,Fi);
    }
    else if(S[X] == 'o' && S[X+1] == 'o'){
        if(A == 1) B = 1;
        else if(A == 2) B = 8;
        else if(A == 7) B = 2;
        else if(A == 8) B = 7;
        solve(X+1,B,Fi);
    }
    else if(S[X] == 'x' && S[X+1] == 'o'){
        if(A == 5) B = 7;
        else if(A == 6) B = 2;
        else if(A == 3) B = 1;
        else if(A == 4) B = 8;
        solve(X+1,B,Fi);
    }
    else{
        if(A == 5) B = 5;
        else if(A == 6) B = 3;
        else if(A == 3) B = 4;
        else if(A == 4) B = 6;
        solve(X+1,B,Fi);
    }
}


signed main() {
    cin.tie(0);
	ios::sync_with_stdio(false);
    cin >> N;
    cin >> S;
    bool OK = 0;
  	S += S[0];
    if(S[0] == 'o' && S[1] == 'o'){
        OK = solve(1,1,1);//Sの文字位置、次の初めの番号、スタート番号
        if(OK) ANS(1);
        OK = solve(1,8,2);
        if(OK) ANS(2);
        OK = solve(1,2,7);
        if(OK) ANS(7);
        OK = solve(1,7,8);
        if(OK) ANS(8);
    }
    else if(S[0] == 'o' && S[1] == 'x'){
        OK |= solve(1,4,1);
        if(OK) ANS(1);
        OK |= solve(1,6,2);
        if(OK) ANS(2);
        OK |= solve(1,3,7);
        if(OK) ANS(7);
        OK |= solve(1,5,8);
        if(OK) ANS(8);
    }
    else if(S[0] == 'x' && S[1] == 'o'){
        OK |= solve(1,7,5);
        if(OK) ANS(5);
        OK |= solve(1,2,6);
        if(OK) ANS(6);
        OK |= solve(1,1,3);
        if(OK) ANS(3);
        OK |= solve(1,8,4);
        if(OK) ANS(4);
    }
    else{
        OK |= solve(1,5,5);
        if(OK) ANS(5);
        OK |= solve(1,3,6);
        if(OK) ANS(6);
        OK |= solve(1,4,3);
        if(OK) ANS(3);
        OK |= solve(1,6,4);
        if(OK) ANS(4);
    }

    cout << -1 << endl;
}