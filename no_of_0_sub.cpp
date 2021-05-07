/*
    Given a array , find no of subarrays with sum equal to 0;
*/

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    //Function to count subarrays with sum equal to 0.
    int findSubarray(vector< int > &arr, int n ) {
        //code here
        unordered_map < int , int > mp1;
        int csum = 0, ans = 0;
        
        for(int i = 0 ; i < n ; ++i){
            csum += arr[i];
            
            if(csum == 0){
                ans+=1;
            }
            
            if(mp1.find(csum) != mp1.end()){
                ans += mp1[csum];
            }
            
            mp1[csum]++;
            
        }
        
        return ans;
        
    }
};

int main(){

    int n;
    cout<<"Enter no of elements: ";
    cin>>n;
    vector<int> vr(n);
    cout<<"Enter elements: ";

    for(int i = 0 ; i < n ; ++i){
        cin>>vr[i];
    }

    Solution sl;
    
    int ans = sl.findSubarray(vr , n );

    cout<<"No of subarrays with sum zero are "<<ans;

    return 0;
}