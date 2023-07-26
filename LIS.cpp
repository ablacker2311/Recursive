#define MAX 100001
#include<iostream>

int dp[MAX]; // mảng lưu chiều dài của mảng không giảm dài nhất tới vị trí thứ i;
int posPrev[MAX]; // mảng lưu vị trí của phần tử trước phần tử có vị trí thứ i trong dãy không giảm

int main(){
    int n;
    std::cin>>n;
    int arr[MAX];

    for(int i = 0;i < n;i++){
        std::cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        dp[i] = 1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if (arr[i] >= arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                posPrev[i] = j;
            }
        }
    }
    int csMax = dp[0];
    int end_index = 0;
    for(int i = 0;i < n;i++){
        if(dp[i] > csMax)
        {
          csMax = dp[i];
          end_index = i;
        }
    }
    int kq[MAX];
    int temp = csMax;
    int k = 0;
    while (temp >= 0){
        kq[temp-1] = arr[end_index];
        end_index = posPrev[end_index];
        temp--;
    }
    
    for(int i=0;i<csMax;i++)
        std::cout<<kq[i]<<" ";

}