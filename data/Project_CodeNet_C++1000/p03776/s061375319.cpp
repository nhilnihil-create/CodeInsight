#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

const double INF=1e15;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    
    vector<long long int> V(N);
    for(int n=0; n<N; n++) {
        cin >> V[n];
    }
    sort(V.begin(), V.end());
    
    double max_av=0;
    for(int a=0; a<A; a++) {
        max_av += (double)V[N-1-a];
    }
    max_av /= (double)A;
    
    cout << setprecision(20) << max_av << endl;
    
    long long int count=0;
    long long int same_nums=upper_bound(V.begin(), V.end(), V[N-1-A])\
    -lower_bound(V.begin(), V.end(), V[N-1-A]);
    long long int upper_nums=V.end()\
    -upper_bound(V.begin(), V.end(), V[N-1-A]);
    
    for(int r=A; r<=B; r++) {
        if(upper_nums>0 && r>A) {
            break;
        }

        long long int tmps=1, tmp=1;
        
        for(int i=0; i<r-upper_nums; i++) {
            tmps *= (same_nums-i);
            tmps /= (i+1);
        }
        // cout << tmps << " ";
        count += tmps;
        if(r>=same_nums) {
            break;
        }
    }

    cout << count << endl;

    return 0;
    
}