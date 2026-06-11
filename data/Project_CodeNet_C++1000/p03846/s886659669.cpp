#include <iostream>
#include <map>

#define INF 1000000007;

int main(){
    int n;
    std::cin >> n;

    std::map<int, int> mp;
    for(int i = 0; i < n; ++i){
        int val;
        std::cin >> val;

        auto itr = mp.find(val);
        if(mp.end() == itr){
            mp.insert(std::make_pair(val, 1));
        }else{
            ++itr->second;
        }
    }

    bool flg = true;
    auto itr = mp.begin();
    int ref = 1 - n % 2;
    while(flg && mp.end() != itr){
        if(mp.begin() == itr){
            flg = ref == itr->first && ref + 1 == itr->second;
        }else{
            flg = ref == itr->first && 2 == itr->second;
        }
        ref += 2;
        ++itr;
    }


    long long ans = 1;
    if(flg){
        for(int i = 0; i < n / 2; ++i){
            ans *= 2;
            ans %= INF;
        }
    }else{
        ans = 0;
    }

    std::cout << ans << std::endl;

    return 0;
}