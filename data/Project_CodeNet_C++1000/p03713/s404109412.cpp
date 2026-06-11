#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    long long h,w;
    long long s1,s2,s3,s4;
    cin >> h >> w;
    long long men = h*w;
    long long santou;
    if(men%3 == 0){
        cout << 0 << endl;
        return 0;
    }else{
        santou = min(h,w);
    }
    if(h%3 == 0){
        if(w%2 == 0){
            cout << 0 << endl;
            return 0;
        }else{
            s1 = (w+1)/2*h/3*2-men/3;
            s2 = s1;
        }
    }else{
        if(w%2 == 0){
            s1 = (h/3+1)*w-(h-(h/3+1))*w/2;
            s2 = (h-h/3)*w/2-h/3*w;
        }else{
            s1 = (h/3+1)*w-(h-(h/3+1))*(w-1)/2;
            s2 = (h-h/3)*(w+1)/2-h/3*w;
        }
    }
    if(w%3 == 0){
        if(h%2 == 0){
            cout << 0 << endl;
            return 0;
        }else{
            s3 = (h+1)/2*w/3*2-men/3;
            s4 = s1;
        }
    }else{
        if(h%2 == 0){
            s3 = (w/3+1)*h-(w-(w/3+1))*h/2;
            s4 = (w-w/3)*h/2-w/3*h;
        }else{
            s3 = (w/3+1)*h-(w-(w/3+1))*(h-1)/2;
            s4 = (w-w/3)*(h+1)/2-w/3*h;
        }
    }
    cout << min(santou,min(min(s1,s2),min(s3,s4))) << endl; 
    return 0;
}