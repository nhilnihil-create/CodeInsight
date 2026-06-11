#include <iostream>
#include <set>
#include <numeric>
#include <map>
using namespace std;

long long a[100000];
long long b[100000];

long long ans[10];
map <long long, set<long long> > point_map;
set <pair <long long, long long> > checked;
int main(void){
    // Your code here!
    long long H;
    long long W;
    int N;
    cin >> H >> W >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i] >> b[i];
        if(point_map.find(a[i]) == point_map.end()){
            set <long long> tmp = {b[i]};
            point_map[a[i]] = tmp;
        } else {
            point_map[a[i]].insert(b[i]);
        }
    }
    
    for(int i = 0; i < N; i++){
        for(int j = -2; j <= 0; j++){
            for(int k = -2; k <= 0; k++){
                int upper_left_h = a[i] + j;
                int upper_left_w = b[i] + k;
                if(checked.find(make_pair(upper_left_h, upper_left_w)) != checked.end() 
                    || upper_left_h < 1 || upper_left_w < 1 || upper_left_h > H - 2 || upper_left_w > W - 2){
                    continue;    
                }
                int filled_no = 0;
                for(int l = 0; l < 3; l++){
                    for(int m = 0; m < 3; m++){
                        int cur_h = upper_left_h + l;
                        int cur_w = upper_left_w + m;
                        if(point_map.find(cur_h) != point_map.end() && point_map[cur_h].find(cur_w) != point_map[cur_h].end()){
                            filled_no++;
                        }
                    }
                }
                ans[filled_no] ++;
                checked.insert(make_pair(upper_left_h, upper_left_w));
            }
        }
    }
    ans[0] = (H - 2) * (W - 2) - accumulate(ans + 1, ans + 10, (long long) 0);
    for(int i = 0; i < 10; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
