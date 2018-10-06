#include<iostream>
using namespace std ;
int main()
{
    int arr[8][25] = {0};
    int sum = 0,  k = 0 , p=0 , q = 0 , num = 0 , first = 0;
    int total[4] = {0} ;
    int stage[3][100] = {0} ;
    int index[4]= {0} ;
    int min_num[10] ={0};
    for(int i = 0 ; i < 3 ; i++)
    {
        cin>>arr[0][i];
    }
    for(int i = 1 ; i < 7 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            cin>>arr[i][j];
        }
    }
    for(int i = 0 ; i < 3 ; i++)
    {
        cin>>arr[7][i];
    }

    for(int i = 0 ; i < 3 ; i++)
    {
        for(int j = 0 ; j < 3 ; j++)
        {
            stage[0][k] = arr[0][j]+arr[j+1][i];
            k++;
        }
    }
    k = 0;

    for(int i = 0 ; i < 3; i++)
    {
        for(int j = 0 ; j < 9 ; j++)
        {
            stage[1][k] = stage[0][j]+arr[4+q][p] ;
            k++;
            if(k%3 == 0)
            {
                q++;
            }
        }
        q=0;
        p++;
    }
    k=0;
    for(int i = 0 ; i < 27 ; i++)
    {
        stage[2][i] = stage[1][i] + arr[7][k];
        num++;
        if(num%9 == 0)
        {
            k++;
        }
    }

    min_num[0] = stage[0][0];
    for(int i = 0 ; i < 9 ; i++ )
    {

        if(min_num[0] > stage[0][i])
        {
            min_num[0] = stage[0][i];
            index[0] = i;
        }
    }
    index[0] = index[0]/3 + 4;
    min_num[1] = stage[1][0];
    for(int i = 0 ; i< 27 ; i++ )
    {

        if(min_num[1] > stage[1][i])
        {
            min_num[1] = stage[1][i];
            index[1] = i ;
        }
    }
    index[1] = index[1]/9 + 7;
     min_num[2] = stage[2][0];
    for(int i = 0 ; i< 27 ; i++ )
    {

        if(min_num[2] > stage[2][i])
        {
            min_num[2] = stage[2][i];
        }
    }
    first = arr[0][0];
    for(int i = 0 ; i < 3 ; i++)
    {
        if(first > arr[0][i])
        {
            first = arr[0][i];
            index[2] = i ;
        }
    }
    index[2] = index[2]/3 + 1;
    cout<<index[2]<<" "<<first<<endl;
    cout<<index[0]<<" "<<min_num[0]<<endl;
    cout<<index[1]<<" "<<min_num[1]<<endl;
    cout<<"10 "<<min_num[2]<<endl;
}
