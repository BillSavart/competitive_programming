#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

void check_card(string b1, string b2, string b3, string b4, string b5, string w1, string w2, string w3, string w4, string w5){
    int black_num[5], white_num[5];
    string black_suit[5], white_suit[5];
    
    black_num[0] = b1[0] - '0'; black_num[1] = b2[0] - '0'; black_num[2] = b3[0] - '0'; black_num[3] = b4[0] - '0'; black_num[4] = b5[0] - '0';
    black_suit[0] = b1[1]; black_suit[1] = b2[1]; black_suit[2] = b3[1]; black_suit[3] = b4[1]; black_suit[4] = b5[1];

    white_num[0] = w1[0] - '0'; white_num[1] = w2[0] - '0'; white_num[2] = w3[0] - '0'; white_num[3] = w4[0] - '0'; white_num[4] = w5[0] - '0';
    white_suit[0] = w1[1]; white_suit[1] = w2[1]; white_suit[2] = w3[1]; white_suit[3] = w4[1]; white_suit[4] = w5[1];

    sort(black_num, black_num + 5);
    sort(white_num, white_num + 5);

}
void check_winner(){

}

int main(void){
    string b1,b2,b3,b4,b5,w1,w2,w3,w4,w5;
    while(cin >> b1 >> b2 >> b3 >> b4 >> b5 >> w1 >> w2 >> w3 >> w4 >> w5){
        check_card(b1,b2,b3,b4,b5,w1,w2,w3,w4,w5);
    }
    return 0;
}