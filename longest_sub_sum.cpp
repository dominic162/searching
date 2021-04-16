/*
    Given array elements and k, find length of longest subsequence whose sum is k;
*/

#include<iostream>
#include<unordered_map>
using namespace std;

class solution{
    public:
        int* make_arr(int n);

        int sub_sum(int* arr,int n,int k);

        void disp_arr(int* arr,int n);
};

void solution::disp_arr(int* arr,int n){
    cout<<"\nArray elements are: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return ;
}

int solution::sub_sum(int* arr, int n, int k){
    int mlen=0,csum=0;

    unordered_map<int,int> mp1;

    for(int i=0; i<n ;++i){
        csum+=arr[i];
        if(csum==k){
            mlen = i+1;
        }

        if(mp1.find(csum-k)!=mp1.end()){
            mlen = max(mlen,i-mp1[csum-k]);
        }
        if(mp1.find(csum)==mp1.end()){
            mp1.insert({csum,i});
        }

    }

    return mlen;
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
    int n;
    cout<<"Enter number of elements in array: ";
    cin>>n;
    int* arr = sl.make_arr(n);

    int k;
    cout<<"Enter sum: ";
    cin>>k;

    cout<<"Max length of subarray with sum "<<k<<" is "<<sl.sub_sum(arr,n,k);

    sl.disp_arr(arr,n);
    return 0;
}