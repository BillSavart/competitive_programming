/* @JUDGE_ID: BillSavart 10252 C++ "Common Permutation" */

/* @BEGIN_OF_SOURCE_CODE */

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(void){
    string input1,input2;
    int i,k;
    int input1_count[26], input2_count[26];
    char output;

    while(getline(cin,input1)){
        getline(cin,input2);
            
        for(int i = 0; i < 26; i++){
            input1_count[i] = 0;
            input2_count[i] = 0;
        }

        for(int i = 0; i < input1.length(); i++){
            k = input1[i] - 'a';
            input1_count[k]++;
        }
        for(int i = 0; i < input2.length(); i++){
            k = input2[i] - 'a';
            input2_count[k]++;
        }
        
        
        for(int i = 0 ; i < 26; i++){
            if(input1_count[i] > 0 && input2_count[i] > 0){
                output = i + 'a';
                cout << output;
                input1_count[i]--;
                input2_count[i]--;
                i--;
            }
        }
        cout << endl;
    }
    return 0;
}

/* @END_OF_SOURCE_CODE */