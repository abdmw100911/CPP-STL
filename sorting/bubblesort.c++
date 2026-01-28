#include<iostream>
#include<vector>
using namespace std;
/*
void bubbleSort(vector<int> &arr, int n){
    //swap adjacents if they are unordered, repeat this for n-2(if start from 0) and n-1(if start from 1) times
    int temp;
    for(int i=1;i<=n-1;i++){
        //j will iterate till n-i-1 to avoid out of bounds and , to avoid comparing with sorted part
        for(int j=0;j<=n-i-1;j++){
            //unordered condition
            if(arr[j+1]<arr[j]){
                //swap
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
*/

//different loop style
void bubbleSort(vector<int> &arr, int n){
    //swap adjacents if they are unordered, repeat this for n-2(if start from 0) and n-1(if start from 1) times
    int temp;
    for(int i=n-1;i>=1;i--){
        //j will iterate till n-i-1 to avoid out of bounds and , to avoid comparing with sorted part
        for(int j=0;j<i;j++){
            //unordered condition
            if(arr[j+1]<arr[j]){
                //swap
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    vector<int> arr = {5,1,7,9,3};
    int n = arr.size();
    bubbleSort(arr,n);
    //print the sorted array
    for(auto it : arr){
        cout<<it<<" ";
    }
    return 0;
}