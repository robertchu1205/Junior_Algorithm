#include <iostream>
using namespace std;
int number(int i);
int main() {
int n;
cin >> n;
int arr[n];
for(int i=0;i<n;i++) {
    cin >> arr[i];
}
for(int i=0;i<n;i++) {
    cout << number(arr[i]);
    cout << endl;
}
return 0;
}
int number(int input) {
int n0=0;
int n1=1;
int final_n=0;
if(input==0) { return 0; }
else if(input==1) { return 1;}
else {
    for(int i=0;i<input-1;i++) {
        final_n=n0+n1;
        n0=n1;
        n1=final_n;
    }
    return final_n;
}
}
