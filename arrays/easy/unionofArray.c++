#include<bits/stdc++.h>
using namespace std;
vector<int> findUnion(vector<int> arr1, vector<int> arr2){
    int n = arr1.size();
    int m = arr2.size();
    int i = 0;
    int j = 0;
    vector<int> unioN;
    //both i and j are pointing to their respective arrays
    while(i<n && j<m){
        //number in arr1 is smaller
        if(arr1[i]<arr2[j]){
            if(unioN.empty() || unioN.back() != arr1[i])
            unioN.push_back(arr1[i]);
        
            i++;
        }
        //number in arr2 is smaller
        else if(arr2[j]<arr1[i]){
            if(unioN.empty() || unioN.back() != arr2[j])
            unioN.push_back(arr2[j]);
            j++;
        }
        //both are equal
        else if(arr1[i]==arr2[j]){
            if(unioN.empty() || unioN.back() != arr2[j])
            unioN.push_back(arr1[i]);

            i++;
            j++;
        }
    }

    //arr1 is exhausted and i is out of bounds
    while(j<m){
        if(unioN.empty() || arr2[j] != unioN.back()){
            unioN.push_back(arr2[j]);
        }
        j++;
    }

    //arr2 is exhausted and j is out of bounds
    while(i<n){
        if(unioN.empty() || arr1[i] != unioN.back()){
            unioN.push_back(arr1[i]);
        }
        i++;
    }

    return unioN;
}
int main(){
    vector<int> arr1 = {1,1,2,3,4,5};
    vector<int> arr2 = {1,2,2,7,9,9,10};
    vector<int> unioN = findUnion(arr1,arr2);
    for(auto it :unioN ){
        cout<<it<<" ";
    }
    return 0;
}