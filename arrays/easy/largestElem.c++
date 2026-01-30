#include<iostream>
#include<vector>
using namespace std;
//brute force appraoch
void largestBrute(vector<int> arr, int n){
    //sort the array
    int j;
    int temp;
    //taking every element one by one
    for(int i=1;i<n;i++){
        //element locked for comparison
        j=i;
        //swap till left element is greater than current selected element
        while(j>0 && arr[j]<arr[j-1] ){
            //swap
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;

            //decrement j for comparison
            j--;
        }
    }
    //last element of the sorted array is largest
    cout<<arr[n-1];
}

void largestOptimal(vector<int> arr, int n){
    //set largest to the first element of the array
    int largest = arr[0];
    //if any element is greater than largest, replace largest with that element
    //repeat for all elements
    for(int i=1;i<n;i++){
        if(arr[i]>largest){
            largest = arr[i];
        }
    }
    cout<<largest<<endl;
}
int main(){
    vector<int> arr = {5,1,7,9,3};
    int n = arr.size();
    //largestBrute(arr,n);
    largestOptimal(arr,n);
    return 0;
}