#include<bits/stdc++.h>
using namespace std;
int removeDuplicatesSortedBrute(vector<int> &arr){
    set<int> st;
    int n = arr.size();

    //transfer the array into the set
    for(auto it : arr){
        st.insert(it);
    }

    //set now has only the unique elements 
    //k is the number of unique elements in the array
    int k = st.size(); 
    int index = 0;
    for(auto it : st){
        arr[index] = it;
        index++;
    }
    return k;
    //time complexity : O(nlogn);
    //space complexity: O(k);
}

int removeDuplicatesSortedBetter(vector<int> &arr){
    //use unordered set for O(n) time complexity
    //unordered set searches in O(1) time 
    
    //this will keep track of seen numbers(duplicates) while traversing array
    unordered_set<int> seen;

    //this will keep track of the place where unique element will be placed in the array
    int index = 0;
    for(auto it : arr){
        //checking if element was already seen
        if(seen.find(it) == seen.end()){
            //element was not seen
            //insert the element in the set(mark as seen)
            seen.insert(it);

            //place the element at 'index' in the array
            arr[index] = it;

            //move the index forward to place the next unique element
            index++;
        }
        //if element was seen(duplicate) skip it
    }
    //size of the set, is the number of unique elements in the array
    //or index can also be said to be number of unique elements in the array
    int k = seen.size();
    return (index);

    //this is the best(optimal) approach when the duplicates are not adjacent
}

int removeDuplicatesSortedOptimal(vector<int> &arr){
    //keep track of where next unique element will be placed 
    int index = 0;
    int n = arr.size();

    for(int i=0;i<n;i++){
        if(arr[i]!=arr[index]){
            arr[index+1] = arr[i];
            index++;
        }
    }

    //number of unique elements 
    return (index+1);

    //this is the beest approach when duplicates are adjacent
    //1 2 1 3 4 5 1 2 3 
}
int main(){
    vector<int> arr = {1 ,2 ,1, 3, 4, 5, 1, 2, 3 };
    cout<<removeDuplicatesSortedBrute(arr)<<endl;
    //cout<<removeDuplicatesSortedBetter(arr)<<endl;
    //cout<<removeDuplicatesSortedOptimal(arr)<<endl;
    for(auto it : arr){
        cout<<it<<" ";
    }
    return 0;
}