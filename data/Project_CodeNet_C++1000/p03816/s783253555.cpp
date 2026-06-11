#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <stack>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    int N;
    cin >> N;

    int A[N];
    for(int i=0; i<N; i++){
        cin >> A[i];
    }

    map<int, int> m;
    for(int i=0; i<N; i++){
        if(m.count(A[i]) == 0)m[A[i]] = 1;
        else{
            m[A[i]]++;
        }
    }

    int cnt = 0;
    for(auto e : m){
        e.second = e.second % 2;
        if(e.second % 2 == 0) cnt++;
    }

    if(cnt % 2 == 0) cout << m.size() << endl;
    else cout << m.size() - 1 << endl;

    return 0;
}
