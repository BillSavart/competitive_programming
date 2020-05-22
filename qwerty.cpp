/* @JUDGE_ID: BillSavart 10082 C++ "WERTYU" */

/* @BEGIN_OF_SOURCE_CODE */

#include<iostream>
#include<string>

using namespace std;

string transition(string input){
    string output = input;
    for(int i = 0; i < input.length(); i++){
        switch(input[i]){
            //digit
            case '1':
                output[i] = '`';
                break;
            case '2':
                output[i] = '1';
                break;
            case '3':
                output[i] = '2';
                break;
            case '4':
                output[i] = '3';
                break;
            case '5':
                output[i] = '4';
                break;
            case '6':
                output[i] = '5';
                break;
            case '7':
                output[i] = '6';
                break;
            case '8':
                output[i] = '7';
                break;
            case '9':
                output[i] = '8';
                break;
            case '0':
                output[i] = '9';
                break;
            case '-':
                output[i] = '0';
                break;
            case '=':
                output[i] = '-';
                break;

            //uppercase letters
            case 'W':
                output[i] = 'Q';
                break;
            case 'E':
                output[i] = 'W';
                break;
            case 'R':
                output[i] = 'E';
                break;
            case 'T':
                output[i] = 'R';
                break;
            case 'Y':
                output[i] = 'T';
                break;
            case 'U':
                output[i] = 'Y';
                break;
            case 'I':
                output[i] = 'U';
                break;
            case 'O':
                output[i] = 'I';
                break;
            case 'P':
                output[i] = 'O';
                break;
            case '[':
                output[i] = 'P';
                break;
            case ']':
                output[i] = '[';
                break;
            case '\\':
                output[i] = ']';
                break;

            case 'S':
                output[i] = 'A';
                break;
            case 'D':
                output[i] = 'S';
                break;
            case 'F':
                output[i] = 'D';
                break;
            case 'G':
                output[i] = 'F';
                break;
            case 'H':
                output[i] = 'G';
                break;
            case 'J':
                output[i] = 'H';
                break;
            case 'K':
                output[i] = 'J';
                break;
            case 'L':
                output[i] = 'K';
                break;
            case ';':
                output[i] = 'L';
                break;
            case '\'':
                output[i] = ';';
                break;

            case 'X':
                output[i] = 'Z';
                break;
            case 'C':
                output[i] = 'X';
                break;
            case 'V':
                output[i] = 'C';
                break;
            case 'B':
                output[i] = 'V';
                break;
            case 'N':
                output[i] = 'B';
                break;
            case 'M':
                output[i] = 'N';
                break;
            case ',':
                output[i] = 'M';
                break;
            case '.':
                output[i] = ',';
                break;
            case '/':
                output[i] = '.';
                break;
            default:
                output[i] = ' ';
                break;
        }
    }

    return output;
}

int main(void){

    string input;
    string output;
    while(getline(cin,input)){
        output = transition(input);
        cout << output << endl;
    }

    return 0;
}
/* @END_OF_SOURCE_CODE */