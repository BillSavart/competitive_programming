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

string sort_black_num(string b1, string b2, string b3, string b4, string b5){
    string black_num = "";
    black_num += b1[0]; black_num += b2[0]; black_num += b3[0]; black_num += b4[0]; black_num += b5[0];
    sort(black_num.begin(), black_num.end());
    
    return black_num;
}

string sort_white_num(string w1, string w2, string w3, string w4, string w5){
    string white_num = "";
    white_num += w1[0]; white_num += w2[0]; white_num += w3[0]; white_num += w4[0]; white_num += w5[0];
    sort(white_num.begin(), white_num.end());

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
int check_black_num(string black_num, bool black_flush){
    return 0;
}
int check_white_num(string white_num, bool white_flush){
    return 0;
}

int main(void){
    string b1,b2,b3,b4,b5,w1,w2,w3,w4,w5;
    string black_num, black_suit, white_num, white_suit;
    bool black_flush, white_flush;
    while(cin >> b1 >> b2 >> b3 >> b4 >> b5 >> w1 >> w2 >> w3 >> w4 >> w5){
        black_num = sort_black_num(b1,b2,b3,b4,b5);
        black_suit = combine_black_suits(b1,b2,b3,b4,b5);
        white_num = sort_white_num(w1,w2,w3,w4,w5);
        white_suit = combine_white_suits(w1,w2,w3,w4,w5);

        black_flush = check_black_flush;
        white_flush = check_white_flush;

        int black_weight, white_weight;
        black_weight = check_black_num(black_num, black_flush);
        white_weight = check_white_num(white_num, white_flush);

        if(black_weight > white_weight)
            cout << "Black wins." << endl;
        else if(white_weight > black_weight)
            cout << "White wins." << endl;
        else
            cout << "Tie." << endl;
        
    }
    return 0;
}