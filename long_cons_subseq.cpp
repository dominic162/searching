/*
    Given a array find length of longest continuous numbers subsequence;
    subsequence doesn't means continuous
*/

#include<iostream>
#include<unordered_set>
using namespace std;

class solution{
    public:
        int* make_arr(int n);

        int get_ans(int* arr1,int n);

        void disp_arr(int* arr,int n);
};

void solution::disp_arr(int* arr,int n){
    cout<<"\nArray elements are: ";
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }
    return ;
}

int solution::get_ans(int* arr, int n){
    int mlen=0;

    unordered_set<int> st;
    for(int i=0;i<n;++i){
        st.insert(arr[i]);
    }
    int clen=0;
    for(int i=0;i<n;++i){

        if(st.find(arr[i]-1)==st.end()){
            clen=1;
            
            for(int j=1; ;j++){
                if(st.find(arr[i]+j)!=st.end()){
                    clen++;
                }
                else{
                    break;
                }
            }

            mlen=max(mlen,clen);
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
    cout<<"Max length of subsequence with continuous numbers is "<<sl.get_ans(arr,n);

    return 0;
}