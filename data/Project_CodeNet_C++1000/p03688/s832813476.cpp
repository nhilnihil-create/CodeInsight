#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        A[tmp]++;
    }
    bool check = false;
    int k;
    for (int i = 0; i < N; i++) {
        if(A[i] != 0){
            if(check == true){
                No();
                return 0;
            }
            if(i < N-1 && A[i+1] != 0){
                check = true;
                k = i+1;
                i++;
            }
            else{
                check = true;
                k = i;
            }
        }
    }

    int s = A[k-1];
    int t = A[k];
    if( s != 0 && s + 1 <= k && 2*(k-s) <= t){
        Yes();
    }
    else if( s == 0 && k == N-1){
        Yes();
    }
    else if(s == 0 && 2 * k <= N){
        Yes();
    }
    else{
        No();
    }
    

}