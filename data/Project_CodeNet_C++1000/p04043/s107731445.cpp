#include<iostream>

using namespace std;

bool search(int* p);

int main(){
    int a[3];
    int a_size = sizeof(a)/sizeof(a[0]);
    for(int i=0;i<a_size;i++){
        cin >> a[i];
    }
    if(search(a)){
        cout << "YES";
    }else{
        cout << "NO";
    }    

}

bool search(int* p){
    if(*p==5 && *(p+1)==5 && *(p+2)==7)
        return 1;
    else if(*p==5 && *(p+1)==7 && *(p+2)==5)
        return 1;
    else if(*p==7 && *(p+1)==5 && *(p+2)==5)
        return 1;
    else
        return 0;       
}