#include<iostream>
#include <string>

using namespace std;

void move_onto(int a, int b){
    cout << "move " << a << " onto " << b << " " << endl;
}

void move_over(int a, int b){
    cout << "move " << a << " over " << b << " " << endl;
}

void pile_onto(int a, int b){
    cout << "pile " << a << " onto " << b << " " << endl;
}

void pile_over(int a, int b){
    cout << "pile " << a << " over " << b << " " << endl;
}

int main(void){
    int n;
    cin >> n;

    if(n <= 0 || n >= 25)
        return -1;

    int arr[n][n];

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j == 0)
                arr[i][j] = i;
            else
                arr[i][j] = -1;
        }
    }

    string input_str;
    while(getline(cin, input_str)){
        if(input_str == "quit")
            break;
        else if (input_str.empty())
            continue;

        switch(input_str.length()){
            case 13:
                if(input_str[0] == 'm'){
                    int temp_a = input_str[5] - '0';
                    int temp_b = input_str[12] - '0';
                    if(input_str[8] == 'n')
                        move_onto(temp_a, temp_b);
                    else
                        move_over(temp_a, temp_b);
                }
                else{
                    int temp_a = input_str[5] - '0';
                    int temp_b = input_str[12] - '0';
                    if(input_str[8] == 'n')
                        pile_onto(temp_a, temp_b);
                    else
                        pile_over(temp_a, temp_b);
                }
                break;
            case 14:
                break;
            case 15:
                if(input_str[0] == 'm'){
                    int temp_a = (input_str[5] - '0') * 10 + input_str[6] - '0';
                    int temp_b = (input_str[13] - '0') * 10 + input_str[14] - '0';
                    if(input_str[9] == 'n')
                        move_onto(temp_a, temp_b);
                    else
                        move_over(temp_a, temp_b);
                }
                else{
                    int temp_a = (input_str[5] - '0') * 10 + input_str[6] - '0';
                    int temp_b = (input_str[13] - '0') * 10 + input_str[14] - '0';
                    if(input_str[9] == 'n')
                        pile_onto(temp_a, temp_b);
                    else
                        pile_over(temp_a, temp_b);
                }
                break;
        }
    }
}