#include<iostream>
#include<unordered_set>
using namespace std;

class solution{
    public:
        int* make_arr(int n);

        bool sub_sum(int* arr,int n,int k);

        void disp_arr(int* arr,int n);
};

void solution::disp_arr(int* arr,int n){
    cout<<"\nArray elements are: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return ;
}

bool solution::sub_sum(int* arr, int n, int k){
    unordered_set<int> st;
    int csum=0;
    for(int i=0;i<n;++i){
        csum+=arr[i];
        if(csum==k){
            return true;
        }
        if(st.find(csum-k)!=st.end()){
            return true;
        }
        st.insert(csum);
    }   
    return false;
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

    if(sl.sub_sum(arr, n ,k)){
        cout<<"Subarray exist whose sum is "<<k;
    }
    else{
        cout<<"No subarray exist whose sum is "<<k;
    }

    sl.disp_arr(arr,n);
    return 0;
}