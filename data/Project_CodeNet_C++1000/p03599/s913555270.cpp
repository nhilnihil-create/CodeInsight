#include <bits/stdc++.h>
using namespace std;

int main() {
    double a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    double wat,sug,con,watmax;
    double sugmax = 0;
    double conmax = 0;
    for (int x=0; x<=30; x++){
        for (int y=0; y<=30; y++){
            wat = 100*(a*x+b*y);
            if (wat <= f){
                for (int z=0; z<=3000; z++) {
                    for (int w=0; w<=3000; w++){
                        sug = c*z+d*w;
                        if (sug == 0) {
                            con = 0;
                            if (con <= 100*e/(100+e) && con >= conmax){
                                conmax = con;
                                sugmax = sug;
                                watmax = wat;
                            }
                        }
                        else if (wat+sug>0 && wat+sug<=f){ 
                            con = 100*sug / (wat+sug);
                            if (con <= 100*e/(100+e) && con > conmax){
                                conmax = con;
                                sugmax = sug;
                                watmax = wat;
                            }
                            else continue;
                        }
                        else continue;
                    }
                }
            }
            else continue;
        }
    }
    cout << watmax+sugmax << " " << sugmax << endl;
    return 0;
}