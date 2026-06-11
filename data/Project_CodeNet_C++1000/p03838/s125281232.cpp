#include <bits/stdc++.h>
using namespace std;
int main(){
long long H,W; cin>>H>>W;
if(H==W){
cout<<0<<endl;}
else if(W==0){
if(H>0){
cout<<1+H;}
else
cout<<abs(H);}
else if(H<W){
if(0<=H){
cout<<W-H<<endl;}
else if(W<0)
cout<<abs(abs(W)-abs(H));
else
cout<<1+abs(abs(H)-W);}
else{
if(W>=0){
cout<<2+H-W<<endl;}
else if(H<0){
cout<<2+abs(abs(W)-abs(H));}
else
cout<<1+abs(abs(W)-H);}}
