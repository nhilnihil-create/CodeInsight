#include <iostream>
#include <string>
 
using namespace std;


int main() {
	string a,b,c;
  	cin >> a ;
  	cin >> b ;
  	cin >> c ;
	int aa = a.size();
  	int bb = b.size();
  	int cc = c.size();
  	int curr_a =0;
  	int curr_b =0;
  	int curr_c =0;
  	char te = 'a';
  	while(1) {
          //cout<<aa << " " << bb<< " " << cc<< endl;
        
    	if(te=='a'){
          if(a[curr_a] == 'a') {
          	curr_a +=1;
            aa-=1;
            if (aa==0) {
              cout<< 'A';
              break;
            }
          }else {
            te = a[curr_a];
            curr_a +=1;
            aa-=1;
            if (te == 'b' && bb==0) {
                cout<< 'B';
                break;
            } else if (te == 'c' && cc==0) {
                cout<< 'C';
                break;
            }
          }
        } else if(te=='b') {
          if(b[curr_b] == 'b') {
          	curr_b += 1;
            bb-=1;
            if (bb==0) {
              cout<< 'B';
              break;
            }
          }else {
            te = b[curr_b];
           	curr_b += 1;
            bb-=1;
            if (te == 'a' && aa==0) {
                cout<< 'A';
                break;
            } else if (te == 'c' && cc==0) {
                cout<< 'C';
                break;
            }
          }
          
        } else if (te=='c') {
          if(c[curr_c] == 'c') {
          	curr_c += 1;
            cc-=1;
            if (cc==0) {
              cout<< 'C';
              break;
            }
          }else {
            te = c[curr_c];
            curr_c += 1;
            cc-=1;
            if (te == 'a' && aa==0) {
                cout<< 'A';
                break;
            } else if (te == 'b' && bb==0) {
                cout<< 'B';
                break;
            }
          }
          
        }
    }
  
  
  return 0;
}