#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool compare_arr(int pan[], int ans[], int j){
    for(int i = 0 ; i < j; i++){
        if(pan[i] != ans[i])
            return false;
    }
    return true;
}

int main(void){
    string input;
    int pancake[30];
    int max_ans, max_index;
    int count;

    while(getline(cin, input)){

        int j = 0;
        for(int i = 0 ; i < 30; i++)
            pancake[i] = 0;

        //process the input
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

        int answer[j];
        for(int i = 0; i < j; i++){
            cout << pancake[i] << " ";
            answer[i] = pancake[i];
        }
        cout << endl;
        sort(answer, answer + j);
        count = j - 1;
        while(!(compare_arr(pancake, answer, j))){
            max_ans = answer[count];
            max_index = 0;
            for(int i = 0; i < j; i++){
                if(pancake[i] == max_ans)
                    break;
                else
                    max_index++;
            }
           
            if(max_index == j - 1)
                ;
            else if(max_index == 0){
                //flip(1)
                reverse(pancake, (pancake + (count + 1)));
                cout << "1" << " ";
            }
            else{
                reverse(pancake, (pancake + (max_index + 1)));
                reverse(pancake, (pancake + (count + 1)));
                cout << (max_index + j) << " ";
            }
            count--;
            
        }    
        cout << "0" << endl; 

    }   
    return 0;
}