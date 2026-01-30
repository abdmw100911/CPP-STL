#include<iostream>
#include<vector>
using namespace std;
bool checkSortedBrute(vector<int> arr, int n){
    //5 1 7 9 3
    //take every element and check whether it is smaller than all of its future elements 
    //do this for all element
    //even if one element fails , the array is not sorted

    //edge case: if array has fewer than 2 elements 
    if(n<2){
        return true;
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                return false;
            }
        }
    }
    return true;

    //time complexity : O(n2);
}

bool checkSortedOptimal(vector<int> arr, int n){
    //1 2 3 4 5
    //in a sorted array, every element is smaller than its next element 
    //traverse through the array and check the same 
    //if any element is greater than its next element , return false

    //edge case
    if(n<2){
        return true;
    }

    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> arr = {1,1,1,1,0};
    int n = arr.size();
    //cout<<checkSortedBrute(arr,n);
    cout<<checkSortedOptimal(arr,n);
    return 0;
}