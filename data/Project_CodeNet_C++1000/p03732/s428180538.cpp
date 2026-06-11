#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;

int main(){
    int N;
    long long W;
    vector<long long> vs_1, vs_2, vs_3, vs_4;
    long long w, v, w1;
    cin >> N >> W;
    cin >> w1 >> v;
    vs_1.push_back(v);
    for(int i=1; i<N; i++){
        cin >> w >> v;
        switch(w-w1){
            case 0:
                vs_1.push_back(v);
                break;
            case 1:
                vs_2.push_back(v);
                break;
            case 2:
                vs_3.push_back(v);
                break;
            case 3:
                vs_4.push_back(v);
        }
    }
    sort(vs_1.begin(), vs_1.end(), greater<long long>());
    sort(vs_2.begin(), vs_2.end(), greater<long long>());
    sort(vs_3.begin(), vs_3.end(), greater<long long>());
    sort(vs_4.begin(), vs_4.end(), greater<long long>());
    long long max = 0, tmp, w_sum;
    for(int i=0; i<=vs_1.size(); i++){
        for(int j=0; j<=vs_2.size(); j++){
            for(int k=0; k<=vs_3.size(); k++){
                for(int l=0; l<=vs_4.size(); l++){
                    w_sum = w1*i + (w1+1)*j + (w1+2)*k + (w1+3)*l;
                    if(w_sum > W) continue;
                    tmp = accumulate(vs_1.begin(), vs_1.begin()+i, 0)
                    + accumulate(vs_2.begin(), vs_2.begin()+j, 0)
                    + accumulate(vs_3.begin(), vs_3.begin()+k, 0)
                    + accumulate(vs_4.begin(), vs_4.begin()+l, 0);
                    if(max <= tmp) max = tmp;
                }
            }
        }
    }
    cout << max;
    return EXIT_SUCCESS;
}