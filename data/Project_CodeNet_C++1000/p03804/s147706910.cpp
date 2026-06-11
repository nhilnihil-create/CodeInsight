#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <iomanip>
#define ll long long

using namespace std;

long long MOD = 1000000007;

bool judge(int y, int x, vector<vector<char>> &A, vector<vector<char>> &B){
    int M=B.size();
    for(int i=0; i<M; i++){
        for(int j=0; j<M; j++){
            if(A[y+i][x+j]!=B[i][j]){
                return false;
            }
        }
    }
    return true;
}

int main(){
    int N, M;
    cin >> N >> M;

    vector<vector<char>> A(N,vector<char>(N));
    for(auto &line:A){
        for(auto &a:line){
            cin >> a;
        }
    }
    vector<vector<char>> B(M,vector<char>(M));
    for(auto &line:B){
        for(auto &b:line){
            cin >> b;
        }
    }

    for(int i=0; i<N-M+1; i++){
        for(int j=0; j<N-M+1; j++){
            if(judge(i,j,A,B)){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}