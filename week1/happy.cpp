#include <iostream>
#include <math.h>
using namespace std;
bool div(int i);
int main() {
   int input;
   int n;
   cin >> n;
   int arr[n];
   for(int i=0;i<n;i++) {
        cin >> arr[i]; }
   for(int i=0;i<n;i++) {
    if(div(arr[i])) {
        cout << "Happy" << endl;
    }
    else {
        cout << "Not Happy" << endl;
    }
   }
    return 0;
}
bool div(int i) {
    int add=0;
    if (i==1) {
        return true;
    }
    else if (i<10)
    {
        return false;
    }
    else {
        while(i>0) {
        add+=pow(i%10,2);
        i=i/10;
        }
        div(add);
    }
}
