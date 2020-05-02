#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

// S = Spades, H = Hearts, D = Diamonds, C = Clubs

string combine_black_suits(string b1, string b2, string b3, string b4, string b5){
    string black_suit = "";
    black_suit += b1[1]; black_suit += b2[1]; black_suit += b3[1]; black_suit += b4[1]; black_suit += b5[1];

    return black_suit;
}
string combine_white_suits(string w1, string w2, string w3, string w4, string w5){
    string white_suit = "";
    white_suit += w1[1]; white_suit += w2[1]; white_suit += w3[1]; white_suit += w4[1]; white_suit += w5[1];

    return white_suit;
}

string pick_black_num(string b1, string b2, string b3, string b4, string b5){
    string black_num = "";
    black_num += b1[0]; black_num += b2[0]; black_num += b3[0]; black_num += b4[0]; black_num += b5[0];
    
    return black_num;
}

string pick_white_num(string w1, string w2, string w3, string w4, string w5){
    string white_num = "";
    white_num += w1[0]; white_num += w2[0]; white_num += w3[0]; white_num += w4[0]; white_num += w5[0];

    return white_num;
}

bool check_black_flush(string black_suit){
    if(black_suit == "CCCCC")
        return true;
    else if(black_suit == "DDDDD")
        return true;
    else if(black_suit == "HHHHH")
        return true;
    else if(black_suit == "SSSSS")
        return true;
    else
        return false;
}
bool check_white_flush(string white_suit){
    if(white_suit == "CCCCC")
        return true;
    else if(white_suit == "DDDDD")
        return true;
    else if(white_suit == "HHHHH")
        return true;
    else if(white_suit == "SSSSS")
        return true;
    else
        return false;
}
int check_black_num(string black_num, bool is_black_flush){
    int black_int[5];
    for(int i = 0; i < 5; i++){
        if(black_num[i] == 'T')
            black_int[i] = 10;
        else if(black_num[i] == 'J')
            black_int[i] = 11;
        else if(black_num[i] == 'Q')
            black_int[i] = 12;
        else if(black_num[i] == 'K')
            black_int[i] = 13;
        else if(black_num[i] == 'A')
            black_int[i] = 1;
        else
            black_int[i] = black_num[i] - '0';
    }
    sort(black_int, black_int + 5);
    


    return 0;
}
int check_white_num(string white_num, bool is_white_flush){
    int white_int[5];
    for(int i = 0; i < 5; i++){
        if(white_num[i] == 'T')
            white_int[i] = 10;
        else if(white_num[i] == 'J')
            white_int[i] = 11;
        else if(white_num[i] == 'Q')
            white_int[i] = 12;
        else if(white_num[i] == 'K')
            white_int[i] = 13;
        else if(white_num[i] == 'A')
            white_int[i] = 1;
        else 
            white_int[i] = white_num[i] - '0';
    }
    sort(white_int, white_int + 5);



    return 0;
}

int main(void){
    string b1,b2,b3,b4,b5,w1,w2,w3,w4,w5;
    string black_num, black_suit, white_num, white_suit;
    bool is_black_flush, is_white_flush;
    while(cin >> b1 >> b2 >> b3 >> b4 >> b5 >> w1 >> w2 >> w3 >> w4 >> w5){
        black_num = pick_black_num(b1,b2,b3,b4,b5);
        black_suit = combine_black_suits(b1,b2,b3,b4,b5);
        white_num = pick_white_num(w1,w2,w3,w4,w5);
        white_suit = combine_white_suits(w1,w2,w3,w4,w5);

        is_black_flush = check_black_flush(black_suit);
        is_white_flush = check_white_flush(white_suit);

        int black_weight, white_weight;
        black_weight = check_black_num(black_num, is_black_flush);
        white_weight = check_white_num(white_num, is_white_flush);

        if(black_weight > white_weight)
            cout << "Black wins." << endl;
        else if(white_weight > black_weight)
            cout << "White wins." << endl;
        else
            cout << "Tie." << endl;
        
    }
    return 0;
}