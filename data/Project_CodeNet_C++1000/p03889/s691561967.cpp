#include <bits/stdc++.h>
int main(){
    std::string a,b;
    int i = 0;
    for(std::cin>>a,b=a,reverse(a.begin(),a.end()); i<a.size(); ++i)
    	a[i] = (a[i]=='b')?'d':((a[i]=='d')?'b':(a[i]=='p')?'q':'p');
    puts(a==b?"Yes":"No");
}