#include <iostream>
#include <math.h>
using namespace std;
int main() {
int input;
cin >> input;
int prime[100];
bool test;
int num=1;
prime[0]=2;
for(int i=2;i<300;i++) {
        test=1;
    for(int j=2;j<sqrt(i)+1;j++) {
        if(i%j==0)
        {
           test=0;
           break;
        }
    }
    if(test==1) {
        prime[num]=i;
        num++;
    }
}
cout << input;
int i=0;                                //質因數陣列序列
int print=0;                            //要印=還是*
int time=0;                             //次方
while(input!=1)
{
    if(input%prime[i]==0)
    {
        while(input%prime[i]==0)
        {
            input=input/prime[i];
            time++;
        }
        if(print==0)  {
            if(time==1) {
                    cout << "=" << prime[i];
            }
            else {
                    cout << "=" << prime[i] << "^" << time;
            }
        }
        else {
            if(time==1) {
                    cout << "*" << prime[i];
            }
            else {
                    cout << "*" << prime[i] << "^" << time;
            }
        }
         print=1;
    }
    time=0;
    i++;
}
return 0;
}
