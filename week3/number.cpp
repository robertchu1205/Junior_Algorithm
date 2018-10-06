#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int main() {
int data=0;
int n,m=0;
int left,right;
int shift;
int main=0,compare=1;
char arr[100][51];
cin >> data;
while(data>0) {
    cin >> n >> m;
    int com[m];             //複雜程度
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cin >> arr[i][j];
        } }
        for(int i=0;i<m;i++) {
            main=0;         //main主要跟別人比的
            compare=1;      //compare要比的，所以是main的下一位
            com[i]=0;
            while(main<n-1) {
            while(compare<n) {
                if(arr[i][main]>arr[i][compare])
                {
                    com[i]++;
                }
                compare++;
            }
                main++;
                compare=main+1;
            } }
//             for(int j=0;j<m;j++) {
//            cout << com[j] << endl; }
        left=0;
        right=m-1;
        while(left!=right) {
            for(int i=left;i<right;i++)
            {
                if(com[i]>com[i+1])
                    {
                        swap(com[i],com[i+1]);
                        for(int x=0;x<n;x++) {
                            swap(arr[i][x],arr[i+1][x]);
                        }
                    }
                    shift=i;
            }
            right=shift;
            for(int i=right;i>left;i--)
            {
                if(com[i]<com[i-1])
                {
                        swap(com[i],com[i-1]);
                      for(int x=0;x<n;x++) {
                            swap(arr[i][x],arr[i-1][x]);
                        }
                }
                shift=i;
            }
            left=shift;
        }
        cout << endl;
         for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            cout << arr[i][j];
        }
        cout << endl; }
    data--;
    cout << endl;
}
return 0;
}
