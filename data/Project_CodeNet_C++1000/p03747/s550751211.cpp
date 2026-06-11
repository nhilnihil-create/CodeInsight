#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
//long long mo = 1e9 + 7;

int main(){
    int N,L,T;
    cin >> N >> L >> T;
    vector<int> X(N);
    vector<int> W(N);
    vector<int> A(N);
    vector<int> R(N);
    rep(i,N){
        cin >> X[i] >> W[i];
        if(W[i] == 1){
            A[i] = X[i] + T;
            A[i] %= L; 
        }else{
            A[i] = X[i] - T;
            A[i] %= L;
            if(A[i] < 0) A[i] += L;
        }
    }
    int cnt = 0;
    //int tmp = 0;
    rep(i,N){
        if(W[i] == 1){
            cnt += (X[i]+T)/L;
        }else{
            cnt -= (T + L - X[i]-1)/L;
            //cnt -= (T - (X[i] + 1) + L) / L;
            //cnt += (T / L);
            //if((T%L) < X[i]) cnt -= 1; 
        }
    }
    sort(A.begin(), A.end());

    //cnt = (cnt % N + N) % N;
    cnt = ((cnt % N) + N) % N; 
    //cout << cnt << endl;
    for (int i = 0; i < N; ++i) R[i] = A[(i+cnt)%N]; //R[(i+cnt)%N] = A[i];
    for (int i = 0; i < N; ++i) cout << R[i] << endl;
    /*
    int cnt = 0;
    int itr = 0;
    int rec = A[0];4 20 9
7 2
9 1
12 1
18 1
    for(int i=1;i<N;i++){
        if(W[0] == 1){
            if(W[0] != W[i]){
                if(X[i] - X[0] < 2*T) cnt++;
            } 
        }else{
            if(W[0] != W[i]){
                if(L-(X[i] - X[0]) <2*T) cnt++;
            }
        }
    }
    sort(A.begin(), A.end());
    if(W[0] == 1){
    rep(i,N){
        if(rec == A[i]){
            if(W[0] == 1){
                if(i - cnt < 0){
                    itr = i-cnt+N;
                }else{
                    itr = i-cnt;
                } 
            }else{
                if(i-(N-cnt) < 0){
                    itr = i-(N-cnt)+N;
                }else{
                    itr = i-(N-cnt);
                }
            }

            break;
        }
    }
    }else{
        for(int i=N-1;i>=0;i--){
        if(rec == A[i]){
            if(W[0] == 1){
                if(i - cnt < 0){
                    itr = i-cnt+N;
                }else{
                    itr = i-cnt;
                } 
            }else{
                if(i-(N-cnt) < 0){
                    itr = i-(N-cnt)+N;
                }else{
                    itr = i-(N-cnt);
                }
            }
            break;
        }
    }
    }
    for(int i=0;i<N;i++){
        if(i+itr < N){
            cout << A[i+itr] << endl;
        }else{
            cout << A[i+itr-N] << endl;
        }
    }
    */
    //cout << "aaa:"<< rec <<","<<N-cnt<< endl;

}

