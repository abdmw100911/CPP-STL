#include<bits/stdc++.h>
using namespace std;
void rightRotateKBrute(vector<int> &arr, int k){
    int n = arr.size();
    vector<int> temp;

    for(int i=n-k;i<n;i++){
        temp.push_back(arr[i]);
    }
    for(int i=0;i<n-k;i++){
        temp.push_back(arr[i]);
    }
    for(int i=0;i<n;i++){
        arr[i] = temp[i];
    }
}
void reverseArray(vector<int> &arr,int start, int end){
    int i=start;
    int j = end;
    int temp;
    while(i<j){
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
}
void rightRotateOptimal(vector<int> &arr, int k){
    int n = arr.size();
    if(k==0)
    return;
    k = k% n;
    reverseArray(arr,n-k,n-1);
    reverseArray(arr, 0 , n-k-1);
    reverseArray(arr,0,n-1);
}
int main(){
    vector<int> arr = {1,2,3,4,5,6,7,8};
    int k = 0;
    //rightRotateKBrute(arr,k);
    rightRotateOptimal(arr,k);

    for(auto it : arr){
        cout<<it<<" ";
    }
    return 0;
}