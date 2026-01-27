#include<bits/stdc++.h>
using namespace std;
void explainMap(){
    //map stores value in key value format
    //in map keys are unique but values can be duplicated
    //map stores values as pairs
    //map stores value in sorted order of its keys

    //map initializqation and definition
    //elements should be defiened in form of pairs
    map<string,int> mpp = {
        {"1hasnain",26},
        {"zainab", 22}
    };
    //insertion of elements 
    mpp["abdullah"] = 29;
    mpp["husain"] = 12;

    mpp.insert({"2hasnain",222});

    mpp.emplace("3hasnain",22);

    //looping through map
    for(auto it : mpp){
        cout<<"name: "<<it.first<<" roll no: "<<it.second<<endl;
    }

    //accessing elements in map
    cout<<mpp["abdullah"]<<endl;
    cout<<mpp["husain"]<<endl;

    auto it1 = mpp.find("abdullah");
    cout<<(*it1).first<<" "<<it1->second<<endl;

    it1 = mpp.find("hellp");//not in map- will return mpp.end()
    cout<<(*it1).first<<endl;

    //multimap : stores duplicate in sorted order : O(logn)
    //unordered map : stores unique in unsorted order : O(n), worst case: O(n)


}
int main(){
    explainMap();
    return 0;
}