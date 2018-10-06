#include <iostream>
#include <math.h>
using namespace std;
int sub(int time,int input);
int prime[100];
int temp[100];
int first=0;
int tem;
int j=0;
int main() {
int n;
cin >> n;
bool test;
int num=1;
prime[0]=2;
for(int i=2;i<500;i++) {
        test=1;
    for(int j=2;j<=sqrt(i)+1;j++) {
        if(i%j==0)
        {
           test=0;
           break;
        }
    }
    if(test==1) {
        prime[num]=i;
      //  cout << prime[num] << " ";
        num++;
    }
    tem=input;
}
return 0;
}
int sub(int t,int i) {
     while(prime[first]<=tem) {
        first++;
    }
    first--;
   temp[j]

}
