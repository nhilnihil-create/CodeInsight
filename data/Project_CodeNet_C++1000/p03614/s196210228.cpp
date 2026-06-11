#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
    vector<int> x;
    int N, cnt=1, ans=0;
    cin >> N;
    for (int i=0;i<N;i++){
        int a;
        cin >> a;
         x.push_back(a);
    }
    while (cnt){
        cnt=0;
        for (int i=0;i<N;i++){
            if (x[i]==i+1){
                cnt++;
                ans++;
                if (i!=N-1)
                    swap(x[i],x[i+1]);
                else
                    swap(x[i],x[i-1]);
            }
        }
    }
    cout << ans;
    return 0;
}