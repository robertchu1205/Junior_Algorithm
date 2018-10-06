#include <iostream>
#include <math.h>
using namespace std;
int main() {
int n=0;
cin >> n;
int input[n];
for(int i=0;i<n;i++) {
    cin >> input[i];
}
int total=0;
for(int i=0;i<n;i++) {
    for(int j=2;j<sqrt(input[i]);j++)
    {
        if(input[i]%j==0)
        {
            total+=j;
            total+=input[i]/j;
            if(j==sqrt(input[i]))
            {
                total-=j;
            }
        }
    }
    total+=1;
    if(total==input[i])
        {
            cout << input[i] << " ";
        }
    total=0;
}
return 0;
}
