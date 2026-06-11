// 10桁でdouble出力するパターン１ 
// printf("%.10f\n", ma);
// 10桁でdouble出力するパターン２
//cout << fixed << setprecision(10);
//  cout << ma << endl;

/*01 02 03 12 13 23　と６回見ていくパターン 
for(int i=0;i<n-1;i++){
  for(int j=i+1;j<n;j++){
    }
  }
*///vector<vector<int>> data(3, vector<int>(4));//int型の2次元配列(3×4要素の)の宣言
//int64_t a;
//10のi乗pow(10, i);
/*string s; stringでの文字列を数字型に変える方法
  cin >> s;
  rep(i,s.size()-2) {
  int a= (s.at(i)-'0')*100 + (s.at(i+1)-'0')*10+ s.at(i+2) -'0';
    */
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
  double aa,bb,c,d,e,f;
  cin >> aa >> bb >> c >> d >> e >> f ;
  double a = 100*aa;
  double b = 100*bb;
  double noudo = 100*e / (100+e);
  double masternoudo=0;
  double satoumizu = 0;
  double satoushituryou = 0;
  int testcount =0;//test
  int ts=0;
//  cout << noudo << endl;
  for(int A = 1; A*a<=f; A++){
    for(int B=0; A*a+B*b <= f; B++){
      for(int C=0; (C*c*100/(A*a+B*b+C*c) <= noudo) && (A*a+B*b+C*c <= f) ;C++){
        for(int D=0; ((C*c+D*d)*100/(A*a+B*b+C*c+D*d) <= noudo) && (A*a+B*b+C*c+D*d <= f); D++){
          testcount++;
      			double checknoudo = (c*C + d*D)* 100 / (a*A + b*B + c*C + d*D);
      			if((a*A + b*B + c*C + d*D) <= f && checknoudo <= noudo){
           			if(masternoudo <= checknoudo){
            	    masternoudo = checknoudo;
             		satoumizu = a*A + b*B + c*C + d*D;
            		satoushituryou = c*C + d*D;
                    ts = testcount;
		        	   }
			      }	
        }
      }
    }
  }
  
  cout << satoumizu << " " << satoushituryou << endl;
//  cout << testcount << endl;
//  cout << ts << endl;
 

}