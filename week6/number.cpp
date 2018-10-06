#include <iostream>
using namespace std;
int num(int l,int c) {
        int arr[l][l];
        int i=0;
        int j=l-1;
        int lm2=l;
        int add_num=1;
        while(lm2>0) {
            if(i==0) {
            for(int x=0;x<lm2;x++) {
                arr[i][x]=add_num;
                arr[x][i]=add_num;
                arr[j][x]=add_num;
                arr[x][j]=add_num;
                }
            }
            else {
                for(int x=add_num-1;x<lm2+add_num-1;x++) {
                arr[i][x]=add_num;
                arr[x][i]=add_num;
                arr[j][x]=add_num;
                arr[x][j]=add_num;                }
            }
            i++;
            j--;
            add_num++;
            lm2-=2;
        }
        int row=0;
        int column=0;
        int cc=1;
        bool judge=0; //0左下 1右上
        while(cc!=c) {
               // cout << arr[row][column] << " ";
            if(judge==0) {
                if(row+1!=l&&column-1!=-1) {
                row++;
                column--;
                 cc++; }

                else if(column-1==-1&&row+1!=l) {
                    row++;
                    judge=1;
                     cc++;
                }
                else if(row+1==l) {
                    column++;
                    judge=1;
                     cc++;
                }
            }
            else {
                if(row-1!=-1&&column+1!=l) {
                    row--;
                    column++;
                    cc++; }
                else if(row-1==-1&&column+1!=l) {
                    column++;
                    judge=0;
                     cc++;
                }
                else if(column+1==l) {
                    row++;
                    judge=0;
                     cc++;
                }


            }

        }
        return arr[row][column];
//        for(int x=0;x<l;x++) {
//            for(int y=0;y<l;y++) {
//                cout << arr[x][y] << " ";
//            }
//            cout << endl;
//        }
}
int main() {
int n;
int length,count;
cin >> n;
for(int i=0;i<n;i++) {
        cin >> length >> count;
        cout << num(length,count) << endl;
}
return 0;
}
