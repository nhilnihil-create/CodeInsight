#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
using namespace std;


int main(){
    int H, W, N;
    map<pair<int, int>, int> rect;

    cin >> H >> W >> N;
    for(int n = 0; n < N; n++){
        int a, b;
        scanf("%d %d", &a, &b);
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                if(a-i >= 1 && a-i <= H-2 && b-j >= 1 && b-j <= W-2){
                    //printf(":::::%d, %d\n", a-i, b-j);
                    rect[make_pair(a-i, b-j)]++;
                }
            }
        }
    }
    long long res[10] = {};
    res[0] = (1ll)*(H-2)*(W-2);
    for(map<pair<int, int>, int>::iterator i = rect.begin(); i != rect.end(); i++){
        //printf("(x, y) = (%d, %d), cnt = %d\n", i->first.first, i->first.second, i->second);
        res[i->second]++;
        res[0]--;
    }
    for(int i = 0; i < 10; i++){
        cout << res[i] << endl;
    }
    return 0;
}