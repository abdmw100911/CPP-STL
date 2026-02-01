#include<iostream>
#include<vector>
using namespace std;
void leftRotateBrute(vector<int> &arr, int k){
    int n = arr.size();
    // temp - 5 1 
            //0 1
    //arr - 5 1 7 9 3 
    //      0 1 2 3 4

    //arr - 7 9 3 
    //      0 1 2 
    vector<int> temp;
    
    for(int i=0;i<k;i++){
        temp.push_back(arr[i]);
    }
    
    for(int i=k;i<n;i++){
        arr[i-k] = arr[i];
    }
    for(int i=0;i<k;i++){
        arr[n-k+i] = temp [i];
    }
}

void rightRotateBrute(vector<int> arr, int k){
    int n = arr.size();
    vector<int> temp;
    
}
int main(){
    vector<int> arr = {5,1,7,9,3};
    int k = 3;
    leftRotateBrute(arr,k);
    for(int it : arr){
        cout<<it<<" ";
    }
    return 0;
}