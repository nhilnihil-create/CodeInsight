#include <bits/stdc++.h>
using namespace std;

int main(void) {

    int64_t N;
    int64_t side;
    int cnt = 0;
    int64_t sum = 1;

    map<int64_t,int64_t> sides;
    cin >> N;
    
    for(int i=0;i<N;i++) {
        cin >> side;        
        sides[side]++;
    }

//    for(auto &it:sides) {
//        it.second /= 2;
//    }

    for(map<int64_t,int64_t>::reverse_iterator it = sides.rbegin();it != sides.rend();++it) {
        while((it->second-=2) >= 0) {
            if(cnt++ < 2) {
                sum *= it->first;
                if(cnt == 2) break;
            } else {
                break;
            }
        }
        if(cnt == 2)break;
    }

    if(cnt == 2) {
        cout << sum << "\n";
    } else {
        cout << "0\n";
    }
    
    return 0;
}
