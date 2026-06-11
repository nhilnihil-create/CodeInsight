#include <iostream>
#include <map>
#include <utility>
using namespace std;

typedef long long lint;

int main(){
    lint H,W,N;
    cin >> H >> W >> N;
    map<pair<lint,lint>,lint> B;
    lint cnt[10];
    cnt[0]=(H-2)*(W-2);
    for(int i=1;i<=9;i++) cnt[i]=0;

    for(int i=0;i<N;i++){
        lint a,b;
        cin >> a >> b;
        for(int y=-1;y<=1;y++){
            for(int x=-1;x<=1;x++){
                if(a+y<=1 || a+y>=H) continue;
                if(b+x<=1 || b+x>=W) continue;
                B[make_pair(a+y,b+x)]++;
                cnt[B[make_pair(a+y,b+x)]]++;
                cnt[B[make_pair(a+y,b+x)]-1]--;
            }
        }
    }
    for(int i=0;i<10;i++) cout << cnt[i] << endl;

    return 0;
}//