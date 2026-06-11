#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;
#define REP(i, n) for(int (i)=0; (i)<(n); (i)++)
template<typename T>
ostream& operator<<(ostream &s, vector<T> A){ for(int i=0;i<A.size();i++){if(i)s<<" ";s<<A[i];} return s;}

int main(){
    int N, M; cin>>N>>M;
    vector<vector<int>> A(N, vector<int>(M));
    REP(i, N){
        REP(j, M) cin>>A[i][j], A[i][j]--;
    }
    vector<int> num(M);
    vector<int> index(N);
    REP(i, N) num[A[i][0]]++;
    int argmax = 0;
    REP(i, M) if(num[argmax]<num[i]) argmax = i;
    int cnt = M;
    int res = num[argmax];
    set<int> deleted;
    //cout << "=======" << endl;
    //cout << num << endl;
    //cout << argmax << endl;
    //cout << res << endl;
    //cout << "=======" << endl;
    while(cnt>1){
        deleted.insert(argmax);
        num[argmax] = 0;
        cnt--;
        for(int i=0; i<N; i++){
            if(!deleted.count(A[i][index[i]])) continue;
            while(deleted.count(A[i][index[i]])){
                index[i]++;
            }
            num[A[i][index[i]]]++;
        }
        REP(i, M) if(num[argmax]<num[i]) argmax = i;
        res = min(res, num[argmax]);
    //cout << "=======" << endl;
        //cout << num << endl;
        //cout << index << endl;
    //cout << "=======" << endl;
    }    
    cout << res << endl;
    return 0;
}
