#include <iostream>

using namespace std;

int main(){
    int N;
    int a[100];
    int cnt[101] = {0};
    int dist_max = 0;
    int dist_min = 1000;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        cnt[a[i]]++;
        dist_max = max(dist_max, a[i]);
        dist_min = min(dist_min, a[i]);
    }
    if(dist_max == 1){
        if(N != 2)cout << "Impossible" << endl;
        else cout << "Possible" << endl;
        return 0;
    }
    if(dist_min !=  (dist_max+1)/2){
        cout << "Impossible" << endl;
        return 0;
    }
    
    if(dist_max%2 == 0){
        if(cnt[dist_min] != 1){
            cout << "Impossible" << endl;
            return 0;
        }else{
            for(int i = dist_min+1; i <= dist_max; i++){
                if(cnt[i] <= 1) {
                    cout << "Impossible" << endl;
                    return 0;
                }
            }
            cout << "Possible" << endl;
            return 0;
        }
    }else{
        if(cnt[dist_min] != 2){
            cout << "Impossible" << endl;
            return 0;
        }
        for(int i = dist_min; i <= dist_max; i++){
            if(cnt[i] <= 1) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
        cout << "Possible" << endl;
        return 0;
    }
}