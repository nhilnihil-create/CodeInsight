#include <iostream>
using namespace std;

int main() {
	long long h, w; 
	long long z = 100000000000 ;
	cin >> h >> w;
    if (h%3==0) z = 0;
    else z = min(z, w);
    if (w%3==0) z = 0;
    else z = min(z, h);

    long long a, b, c;
    for (int i=1; i<h; i++){
      a = i*w;
      if (w%2==0){
        b = w/2*(h-i);
        z = min(z, abs(a-b));
      }
      else{
        b = w/2*(h-i);
        c = (w/2+1)*(h-i);
        long long n1 = min(a, min(b, c));
        long long n2 = max(a, max(b, c));
        z = min(z, (n2-n1));
      }
    }
    for (int i=1; i<w; i++){
      a = i*h;
      if (h%2==0){
        b = h/2*(w-i);
        z = min(z, abs(a-b));
      }
      else{
        b = h/2*(w-i);
        c = (h/2+1)*(w-i);
        long long n1 = min(a, min(b,c));
        long long n2 = max(a, max(b,c));
        z = min(z, (n2-n1));
      }
    }
    cout << z << '\n';
	
}
