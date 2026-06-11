#include <iostream>
#include <sstream>  // istringstream
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>

using namespace std;

int main()
{   
    long long N, x;
    cin >> N >> x;
    long long a[N];
    for(int i=0; i<N; ++i) cin >> a[i];

    long long count = 0;
    // 2つ組みで検証
    long long dis = 0;
    for(int i=0; i<N-1; ++i){
        dis = a[i] + a[i+1] - x;
        if(dis > 0){
            if(a[i+1] >= dis){
                a[i+1] -= dis;
            }
            else{
                // a[i] -= (dis-a[i+1]);
                a[i+1] = 0;
            }
            count += dis;
        }
    }

    cout << count << endl;
    return 0;
}