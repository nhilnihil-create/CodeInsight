#include<iostream>
#include<vector>
#include<string>

int main(){
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    a *= 100;
    b *= 100;

    // 作れるかどうか
    long double maxConcent = 0.0;
    int outWater = a;
    int outSugar = 0;
    for(int i = 0; i <= f / a; i++){
        for(int j = 0; j <= f / b; j++){
            for(int k = 0; k <= f / c; k++){
                for(int l = 0; l <= f / d; l++){
                    if(a * i + b * j == 0) continue;
                    if(a * i + b * j + c * k + d * l > f) continue;
                    int water = a * i + b * j;
                    int sugar = c * k + d * l;
                    // 溶け残りNG
                    long double maxSugar = (water * e) / 100.0;
                    if(maxSugar < sugar) continue;
                    if(maxConcent < (100.0 * sugar) / (1.0 * (water + sugar))){
                        maxConcent = (100.0 * sugar) / (1.0 * (water + sugar));
                        outWater = water;
                        outSugar = sugar;
                    }
                }
            }
        }
    }

    std::cout << outWater + outSugar << " " << outSugar << std::endl;
    return 0;
}
