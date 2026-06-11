#include <iostream>
using namespace std;

int main() {
    long long n, ng = 0, ok;
    long long a, b, h[100000], c;
    cin >> n >> a >> b;
    c = a - b;
    for(int i=0;i<n;i++){
        cin >> h[i];
    }
    ok = 1e9+1;
    while(ng + 1 < ok){
        long long mid = (ng + ok) / 2, d = 0;
        for(int i=0;i<n;i++){
            long long r = h[i] - b * mid;
            if(r > 0){
                d += (r + c - 1)/c;
            }
        }
        if(d<=mid){
            ok = mid;
        }else{
            ng = mid;
        }
    }
    cout << ok << endl;
	return 0;
}