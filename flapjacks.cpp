#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(void){
    string input;
    int pancake[30];
    while(getline(cin, input)){

        int j = 0;
        for(int i = 0 ; i < 30; i++)
            pancake[i] = 0;

        for(int i = 0; i < input.length(); i++){
            if((input[i] >= 48 && input[i] <= 57) && (input[i+1] >= 48 && input[i+1] <= 57)){
                pancake[j] = ((input[i] - '0') * 10) + (input[i+1] - '0');
                i = i + 2;
            }
            
            else if(input[i] >= 48 && input[i] <= 57)
                pancake[j] = input[i] - '0';
            
            else
                j--;
            j++;
        }

    }
    return 0;
}