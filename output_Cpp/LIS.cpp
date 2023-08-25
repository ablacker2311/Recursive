/*bài này là bài tìm dãy con không giảm dài nhất.
hướng giải quyết => tạo ra 2 mảng, 1 mảng lưu chiều dài của mảng con không giảm dài nhất tới vị trí thứ i -> dp[i]
                    mảng còn lại lưu vị trí của phần tử nằm trước phần tử có vị trí thứ i trong dãy không giảm -> posPrev[i]
ta sử dụng 2 vòng lặp lồng nhau, tại vị trí thứ i thì t xét tất cả các phần tử trước i có thỏa điều kiện là 
arr[i] >= arr[j] và dp[i] < dp[j] + 1 (xét xem độ dài của dãy tại vị trí i có nhỏ hơn độ dài của dãy tại vị trí thứ j + 1 hay không )
điều kiện cơ sở : dp[i] = 1; ( ban đầu t giả sử dãy không giảm có 1 phần tử thì tại mọi vị trí thứ i độ dài đều bằng 1)
    sau khi xét xong các điều kiện trên, ta xét từng phần tử của mảng dp[i] để tìm ra độ dài chuỗi con dài nhất là csMax =dp[i]
 và phần tử cuối cùng của chuỗi con là phần tử arr[i]. (end_index = i)
    sau đó tạo mảng phụ kq[] có csMax phần tử và chạy vòng lặp từ 0-> csMax - 1;
    với kq[csMax - 1] = arr[end_index];
        end_index = posPrev[end_index];

        cuối cùng in ra mảng kq[csMax];
*/

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
    while (temp >= 0){
        kq[temp-1] = arr[end_index];
        end_index = posPrev[end_index];
        temp--;
    }
    
    for(int i=0;i<csMax;i++)
        std::cout<<kq[i]<<" ";

}