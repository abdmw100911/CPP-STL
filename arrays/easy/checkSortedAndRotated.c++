#include<iostream>
#include<vector>
using namespace std;
bool checkSortedAndRotated(vector<int> arr){
    //if array is sorted and rotated
    //4 5 6 1 2 3
    //there are 2 hints that array was originally sorted and then rotated at some position
    /*
    1. arr[0] > arr[n-1]
    2. inside the array there will be only one place where arr[i]>arr[i+1]
    */
    int n=arr.size();
    int count=0;
    if(n<2){
    return true;
    }

    //check rotattion link, if rotattion = 0 , then this will be skipped 
    if(arr[0]<arr[n-1])
    {
        count++;
    }

    //check for rotation point in the array
    //if more than 2 dips are found, it means the array was originally not sorted 
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            count++;
            if(count>1)
            return false;
        }
    }
    return true;
}
int main(){
    vector<int> arr = {1,2,3,4};
    cout<<checkSortedAndRotated(arr);
    return 0;
}