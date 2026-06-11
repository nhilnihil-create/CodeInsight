#include <iostream>
#include <vector>

using namespace std;

long A[100000];
long sum[100001];
long sum_abs[100001];
vector<int> negs;

int main(){
    int N;
    cin >> N;
    //cout << negs.size() << endl;
    long ans;
    sum[0] = 0;
    sum_abs[0] = 0;
    cin >> A[0];
    sum[1] = A[0];
    sum_abs[1] = A[0];
    for(int i = 1; i < N; i++){
        char op;
        cin >> op;
        cin >> A[i];
        if(op == '-') {
            A[i] *= -1;
            negs.push_back(i);
        }
        sum[i+1] = sum[i]+A[i];
        sum_abs[i+1] = sum_abs[i]+abs(A[i]);
    }
    ans = sum[N];
    for(int i = 0; i+1 < negs.size(); i++){
        int l = negs[i];
        int r = negs[i+1];
        long tmp = sum_abs[N]-sum_abs[r] + sum[l+1] - (sum_abs[r]-sum_abs[l+1]);
        ans = max(ans, tmp);
    }
    cout << ans << endl;
}