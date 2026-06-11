#include <bits/stdc++.h>

using namespace std;
using ll = long long;
using ld = long double;

//#define int long long
//signed main(){
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int h,w,n;
    cin >> h >> w >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> c(h*w);
    int k=0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a[i]; j++) {
            c[k]=(i+1);
            k++;
        }
    }

    for(int i = 0; i < h; i++) {
        if(i%2){
            for(int j = 0; j < w; j++) {
                cout << c[i*w+j] << " ";
            }
        }
        else{
            for(int j = 0; j < w; j++) {
                cout << c[i*w+(w-1-j)] << " ";
            }
        }
        cout << "\n";
    }

    return 0;
}