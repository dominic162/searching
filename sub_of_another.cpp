/*
    Check whether a string is subsequence of another string;
*/

#include<iostream>
#include<string>

using namespace std;

int main(){

    string s,r;
    cin>>s;

    cin>>r;

    int i = 0 , j = 0;
    while( i < s.size() && j < r.size() ){

        if( s[i] == r[j]){
            ++j;
        }

        ++i;
    }

    if( j == r.size()){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

    return 0;
}