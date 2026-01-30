#include<iostream>
#include<vector>
using namespace std;
void insertionSort(vector<int> &arr, int n){
    //insertion sort
    //take every element and put 'insert' it in its correct position
    //practically it is done by taking every element and swapping it with its left element if(a[element]<a[element-1]), stop when (a[element]>=a[element-1])

    //5 0 1 0 7 2 9 3

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
}
int main(){
    vector<int> arr = {5,1,7,9,3};
    int n = arr.size();
    insertionSort(arr,n);
    //printing the sorted array
    for(auto it : arr){
        cout<<it<<" ";
    }
    return 0;
}