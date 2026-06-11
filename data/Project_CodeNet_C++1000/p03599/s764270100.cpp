#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<vector>
#include<map>
using namespace std;
int main() {
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    double max = 0.0;
    int situryou = 100*A, yousitu = 0;
    int a = 0, b = 0, c = 0, d = 0;
    for(a = 0; a <= 30;a++){
        for(b = 0; b <= 30;b++){
            int l = 100*A*a + 100*B*b;
            for(c = 0; c <= 100;c++){
                for(d = 0; d <= 100;d++){        
                    int m = C*c + D*d;
                    if(l == 0) break;
                    if(l/100*E >= m && l + m <= F){
                        //比較をする時はdouble型で格納するのが良い
                        double noudo = (double)100*m/(l + m);
                        if(max < noudo){
                            max = noudo;
                            situryou = 100*a*A+100*b*B+C*c+D*d;
                            yousitu  = C*c+D*d; 
                        }
                    } 
                }
            }
        }
    }
    cout << situryou << " " << yousitu << endl;
    return 0;
}