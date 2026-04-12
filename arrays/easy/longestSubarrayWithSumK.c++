#include<bits/stdc++.h>
using namespace std;

int longestSubarrayWithSumK(vector<int> arr, int n, int k){
    //10 5 2 7 1 9
    int subArray = 0;
    int longestSubArray = 0;
    int sum;
    for(int i=0;i<n;i++){
        sum = arr[i];
        //if a single element is equal to k
        if(sum == k){
            subArray = 1;
            longestSubArray = max(subArray,longestSubArray);
        }
        for(int j=i+1;j<n;j++){

            sum += arr[j];

            if(sum == k){
                subArray = (j-i)+1;
                longestSubArray = max(subArray,longestSubArray);
            }
            else if(sum > k){
                break;
            }
        }
    }
    return longestSubArray;
}

int longestSubarrayWithSumKOptimal(vector<int> arr,int n , int k){
    //2 pointer approach
    int i=0;
    int j=0;
    int sum = 0;
    int maxlen = 0;

    while(j<n){
        sum += arr[j];

        //if sum exceeds k
        while(i<=j && sum >k){
            sum -= arr[i];
            i++;
        }

        //if sum == k
        if(sum == k){
            maxlen = max(maxlen,j-i+1);
        }
        
        j++;
    }
    return maxlen;
}
int main(){
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int k = 15;
    int n = arr.size();
    //cout<<longestSubarrayWithSumK(arr,n,k)<<" is the length of longest subArray with sum "<<k<<endl;

    cout<<longestSubarrayWithSumKOptimal(arr,n,k)<<" is the length of longest subArray with sum "<<k<<endl;
    return 0;
}