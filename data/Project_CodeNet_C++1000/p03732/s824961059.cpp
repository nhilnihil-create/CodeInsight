#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <random>

using namespace std;

const long long LLINF = 9223372036854775807;
int main(){
    int n;
    long long w;
    cin >> n >> w;
    long long minW;
    vector<long long> w0,w1,w2,w3;
    for(int i=0;i < n; i++){
        long long weight,value;
        cin >> weight >> value;
        if(i==0){
            minW = weight;
        }
        switch(weight-minW){
            case 0:
                w0.push_back(value);
                break;
            case 1:
                w1.push_back(value);
                break;
            case 2:
                w2.push_back(value);
                break;
            case 3:
                w3.push_back(value);
                break;
        }
    }
    sort(w0.begin(), w0.end());
    sort(w1.begin(), w1.end());
    sort(w2.begin(), w2.end());
    sort(w3.begin(), w3.end());
    reverse(w0.begin(), w0.end());
    reverse(w1.begin(), w1.end());
    reverse(w2.begin(), w2.end());
    reverse(w3.begin(), w3.end());
    long long answer = 0;
    for(long long i=0;i<=(long long)w0.size();i++){
        for(long long j=0;j<=(long long)w1.size();j++){
            for(long long p=0;p<=(long long)w2.size();p++){
                for(long long q=0;q<=(long long)w3.size();q++){
                    if((i+j+p+q) * minW + j + p * 2 + q * 3 > w){
                        continue;
                    }
                    long long buf = 0;
                    for(long long a = 0; a < i ; a++){
                        buf += w0[a];
                    }
                    for(long long a = 0; a < j ; a++){
                        buf += w1[a];
                    }
                    for(long long a = 0; a < p ; a++){
                        buf += w2[a];
                    }
                    for(long long a = 0; a < q ; a++){
                        buf += w3[a];
                    }
                    answer = max(answer, buf);
                }
            }
        }
    }
    cout << answer << endl;
    return 0;
}
