/* @JUDGE_ID: BillSavart 10188 C++ "Automated Judge Script" */

/* @BEGIN_OF_SOURCE_CODE */

#include<iostream>
#include<string>
#include<cctype>

using namespace std;

int main(void){
    int answer_line, summit_line;
    int case_num = 1;

    string input;

    while(cin >> answer_line && answer_line != 0){
        bool AC = true, PE = true, WA = true;

        string answer = "", summit = "";

        getchar();
        for(int i = 0 ; i < answer_line; i++){
            getline(cin, input);
            if(i > 0){
                answer = answer + '\n', answer = answer + input;
            }
            else
                answer = input;
        }
        
        cin >> summit_line;
        getchar();
        for(int i = 0; i < summit_line; i++){
            getline(cin, input);
            if(i > 0){
                summit = summit + '\n', summit = summit + input;
            }
            else
                summit = input;
        }

        if(answer != summit){
            AC = false;
        }
        
        for(int i = 0; i < answer.length(); i++){
            if(!isdigit(answer[i])){
                answer.erase(i, 1), i--;
            }
        }
        for(int i = 0; i < summit.length(); i++){
            if(!isdigit(summit[i])){
                summit.erase(i, 1), i--;
            }
        }

        if(answer != summit)
            PE = false;
        
        cout << "Run #" << case_num << ": ";
        if(AC)
            cout << "Accepted" << endl;
        else if(PE)
            cout << "Presentation Error" << endl;
        else
            cout << "Wrong Answer" << endl;
        

        case_num++;
    }
    return 0;
}

/* @END_OF_SOURCE_CODE */