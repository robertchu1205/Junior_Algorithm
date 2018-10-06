#include <iostream>

using namespace std;

int FindMaxIndex(int sol[], int StrainNum,int N, int S);
bool Check(int sol[], int N, int S);
void PrimeSolution(int sol[], int StrainNum,int N, int S);

static int prime[62] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223};

int main()
{
    int exeTime = 0;
    int N = 0,S = 0;
    int *sol;   //質數解
    int *solPrimeNum;   //質數解對應質數陣列索引
    cin >> exeTime;
    
    for (int i = 0; i < exeTime; i++)
    {
        cin >> N >> S;
        sol = new int[N];
        for (int j = 0 ; j < N; j++)   sol[j] = 2;  //預設所有皆為2
        
        solPrimeNum = new int[N];
        
        PrimeSolution(sol, N-1, N, S);
        
    }
    
    return 0;
}

void PrimeSolution(int sol[], int StrainNum,int N, int S)
{
    if (N >= S)   // N >= S 回傳0
    {
        cout << 0 << endl;
        return;
    }
    
    for (int i = FindMaxIndex(sol, StrainNum, N, S); i >= 0; i--)  //從陣列和<S範圍內找出最大質數 開始往下判斷
    {
        int temp = sol[StrainNum];   //記錄原本的值
        sol[StrainNum] = prime[i];
        
        if (sol[StrainNum+1] != 0 && sol[StrainNum] > sol[StrainNum+1])  //若目前位數>下一位 則還原數值並結束
        {
            sol[StrainNum] = temp;
            return;
        }
//測試用
//        printf("StrainNum = %d, i = %d, \n", StrainNum, i);
//
//        for (int j = 0; j < N; j++) cout << " " << sol[j];
//        cout << endl;
////
        
        if (Check(sol, N, S))   //判斷是否符合條件
        {
            for (int j = 0; j < N; j++) cout  << sol[j] << " ";
            cout << endl;
        }
        else   //不符合條件則把下一位當作應變數繼續判斷 直到首位判斷完成
        {
            if (StrainNum != 0)  PrimeSolution(sol, StrainNum-1, N, S);
        }
    }
    return;
}

bool Check(int sol[], int N, int S)  //判斷陣列和是否符合條件
{
    int sum = 0;
    for (int i = 0; i < N; i++) sum += sol[i];
    if (sum == S) return true;
    else return false;
}


int FindMaxIndex(int sol[], int StrainNum,int N, int S)  //找出陣列和在S範圍內的最大質數對應的質數索引
{
    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        if(i != StrainNum) sum += sol[i];
    }
    
    int i = 0;
    while (prime[i] <= (S-sum))
    {
        i++;
    }
    return i-1;
}