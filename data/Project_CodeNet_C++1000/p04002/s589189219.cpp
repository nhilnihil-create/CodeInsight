#include <bits/stdc++.h>

using namespace std;

const int N = 55;
//51min!!
const int mod = 1e9+7;

int h;
int w;
int n;
long long ans[11];
set < pair < int , int > > grid , points;

int main(){
    scanf("%d%d%d" , &h , &w , &n);
    long long subgrids = 1LL * (h - 2) * (w - 2);
    //cout << subgrids << "\n";
    for(int i = 1; i <= n; i++){
        int x , y;
        scanf("%d%d" , &x , &y);
        points.insert({x , y});
        for(int a = -2; a <= 0; a++)
            for(int b = -2; b <= 0; b++)
                    grid.insert({x + a , y + b});
    }
    long long sum = 0;
    auto it = grid.begin();
    for(; it != grid.end(); it++){
        int cnt = 0;
        int x = it->first;
        int y = it->second;
        if(x < 1 || x > h-2 || y < 1 || y > w - 2)
            continue;
        for(int i = 0; i <= 2; i++)
            for(int j = 0; j <= 2; j++)
                if(points.find({x+i , y+j}) != points.end()){
                    cnt++;
                }
        //if(x + 2 <= h && y + 2 <= w){
            sum ++;
            ans[cnt]++;
        //}
    }
    ans[0] = subgrids - sum;
    for(int i = 0; i <= 9; i++){
        printf("%lld\n" , ans[i]);
    }
}
