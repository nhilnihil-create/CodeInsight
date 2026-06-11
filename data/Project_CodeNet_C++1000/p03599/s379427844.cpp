#include<iostream>
#include<vector>
using namespace std;
int main(){
    int A, B, C, D, E, F;
    double concentration, ans = 0.0;
    int ans_sugarWater = 0, ans_sugar = 0;
    vector<int> water, sugar;
    cin >> A >> B >> C >> D >> E >> F;

    for(int b = 0; b <= F / (100 * B); b++){
        for(int a = 0; a <= (F - (b * 100 * B)) / (100 * A); a++){
            water.push_back(a * 100 * A + b * 100 * B);
        }
    }

    for(int b = 0; b <= F / D; b++){
        for(int a = 0; a <= (F - b * D) / C; a++){
            sugar.push_back(a * C + b * D);
        }
    }

    for(int x : water){
        for(int y : sugar){
            if(x + y == 0) concentration = 0;
            else concentration = (double)y / (x + y);
            if(x + y <= F && (x / 100.0) * E >= y && concentration >= ans){
                ans = concentration;
                ans_sugarWater = x + y;
                ans_sugar = y;
            }

        }
    }
    cout << ans_sugarWater << " " << ans_sugar << endl;
}