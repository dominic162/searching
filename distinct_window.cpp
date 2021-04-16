/*
    Given an array , find no of distinct elements in all window of size k;
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        int* make_arr(int n);

        void get_ans(int* arr1,int n , int k);

        void disp_arr(int* arr,int n);
};

void solution::disp_arr(int* arr,int n){
    cout<<"\nArray elements are: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return ;
}

void solution::get_ans(int* arr, int n , int k){
    
    unordered_map<int,int> mp;

    for(int i=0;i<k;++i){
        if(mp.find(arr[i])!=mp.end()){
            mp[arr[i]]++;
        }
        else{
            mp[arr[i]]=1;
        }
    }
    cout<<mp.size()<<" ";
    for(int i=k;i<n;++i){

        if(mp.find(arr[i])!=mp.end()){
            mp[arr[i]]++;
        }
        else{
            mp[arr[i]]=1;
        }
        mp[arr[i-k]]--;
        if(mp[arr[i-k]]==0){
            mp.erase(arr[i-k]);
        }

        cout<<mp.size()<<" ";

    }

    return ;

}

int* solution::make_arr(int n){
    int* arr = new int[n];

    cout<<"Enter elements of array: ";
    for(int i=0;i<n;++i){
        cin>>arr[i];
    }
    return arr;

}

int main(){
    solution sl;
    int n,k;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int* arr = sl.make_arr(n);

    cout<<"Enter window size: ";
    cin>>k;

    cout<<"Distinct elements in every window of size k are: ";
    sl.get_ans(arr,n,k);

    return 0;
}