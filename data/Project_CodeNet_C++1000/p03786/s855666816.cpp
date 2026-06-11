#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    int N;  cin >> N;
    vector<ll> A(N);
    for(int i=0; i<N; i++)  cin >> A[i];
    sort(all(A));

    ll mass = A[0];
  	int j = 0;
    for(int i=1; i<N; i++){
        if(A[i] > 2*mass){
            j = i;
        }
        mass += A[i];
    }
    cout << N - j << endl;
    return 0;
}