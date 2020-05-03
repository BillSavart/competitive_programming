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
    
    //str_flush = 8000, foak = 7000, full = 6000, flush = 5000, straight = 4000, toak = 3000, two_pairs = 2000, pair = 1000, highcard = 0;
    
    //check straight
    bool is_straight = true;

    for(int i = 0; i < 4; i++){
        if(black_int[i+1] != (black_int[i] + 1)){
            is_straight = false;
            break;
        }
    }
    //ATJQK
    if(black_int[0] == 1 && black_int[1] == 10 && black_int[2] == 11 && black_int[3] == 12 && black_int[4] == 13)
        is_straight = true;

    int count[5] = {0,0,0,0,0};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(black_int[i] == black_int[j])
                count[i]++;
        }
    }

    //straight flush
    if(is_straight && is_black_flush){
        return 8000;
    }
    else if(is_black_flush && !is_straight){
        //flush
        return 5000;
    }
    else if(!is_black_flush && is_straight){
        //straight
        return 4000;
    }

    //foak
    if(count[2] == 4){
        if(black_int[2] == 1)
            black_int[2] = 14;

        int foak_value = 7000 + black_int[2];
        return foak_value;
    }
    else if(count[2] == 3 && (count[0] == 2 || count[4] == 2)){
        //full house
        if(black_int[2] == 1)
            black_int[2] = 14;

        int full_value = 6000 + black_int[2];
        return full_value;
    }
    else if(count[2] == 3 && (count[0] == 1 || count[4] == 1)){
        //toak
        if(black_int[2] == 1)
            black_int[2] = 14;

        int toak_value = 3000 + black_int[2];
        return toak_value;
    }

    sort(count, count + 5);
    if(count[1] == 2 && count[3] == 2){
        //two_pairs
        return 2000;
    }
    else if(count[1] != 2 && count[3] == 2){
        //pair
        return 1000;
    }
    else if(count[4] == 1){
        //highcard
        return 0;
    }

    return -1; //if fail to recognize the cards
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

    //strflush = 8000, foak = 7000, full = 6000, flush = 5000, straight = 4000, toak = 3000, tpair = 2000, pair = 1000, highcard = 0;
    
    //check straight
    bool is_straight = true;

    for(int i = 0; i < 4; i++){
        if(white_int[i+1] != (white_int[i] + 1)){
            is_straight = false;
            break;
        }
    }
    //ATJQK
    if(white_int[0] == 1 && white_int[1] == 10 && white_int[2] == 11 && white_int[3] == 12 && white_int[4] == 13)
        is_straight = true;

    int count[5] = {0,0,0,0,0};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(white_int[i] == white_int[j])
                count[i]++;
        }
    }

    //straight flush
    if(is_straight && is_white_flush){
        return 8000;
    }
    else if(is_white_flush && !is_straight){
        //flush
        return 5000;
    }
    else if(!is_white_flush && is_straight){
        //straight
        return 4000;
    }

    //foak
    if(count[2] == 4){
        if(white_int[2] == 1)
            white_int[2] = 14;

        int foak_value = 7000 + white_int[2];
        return foak_value;
    }
    else if(count[2] == 3 && (count[0] == 2 || count[4] == 2)){
        //full house
        if(white_int[2] == 1)
            white_int[2] = 14;

        int full_value = 6000 + white_int[2];
        return full_value;
    }
    else if(count[2] == 3 && (count[0] == 1 || count[4] == 1)){
        //toak
        if(white_int[2] == 1)
            white_int[2] = 14;

        int toak_value = 3000 + white_int[2];
        return toak_value;
    }

    sort(count, count + 5);

    if(count[1] == 2 && count[3] == 2){
        //two_pairs
        return 2000;
    }
    else if(count[1] != 2 && count[3] == 2){
        //pair
        return 1000;
    }
    else if(count[4] == 1){
        //highcard
        return 0;
    }

    return -1; //if fail to recognize the cards
}

void check_tie(string black_num, string white_num, int weight){
    int white_int[5], black_int[5];
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
            white_int[i] = 14;
        else 
            white_int[i] = white_num[i] - '0';

        if(black_num[i] == 'T')
            black_int[i] = 10;
        else if(black_num[i] == 'J')
            black_int[i] = 11;
        else if(black_num[i] == 'Q')
            black_int[i] = 12;
        else if(black_num[i] == 'K')
            black_int[i] = 13;
        else if(black_num[i] == 'A')
            black_int[i] = 14;
        else 
            black_int[i] = black_num[i] - '0';
    }
    sort(black_int, black_int + 5);
    sort(white_int, white_int + 5);
    
    int black_count[5] = {0,0,0,0,0};
    int white_count[5] = {0,0,0,0,0};
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(black_int[i] == black_int[j])
                black_count[i]++;
            if(white_int[i] == white_int[j])
                white_count[i]++;
        }
    }

    if(weight == 8000 || weight == 5000 || weight == 4000 || weight == 0){
        //compare the highest cards, straight flush , flush, straight, highcards
        for(int i = 4; i >= 0; i--){
            if(black_int[i] > white_int[i]){
                cout << "Black wins." << endl;
                return;
            }
            else if(white_int[i] > black_int[i]){
                cout << "White wins." << endl;
                return;
            }
            else
                ;
        }
        cout << "Tie." << endl;
        return;
    }
    else if(weight == 2000){
        int black_pair_max = 0, black_pair_min = 0, white_pair_max = 0, white_pair_min = 0;
        int black_rest, white_rest;

        for(int i = 0; i < 5; i++){
            if(black_count[i] == 1)
                black_rest = black_int[i];
            if(white_count[i] == 1)
                white_rest = white_int[i];
        }

        
    }
    else if(weight == 1000){
        int black_pair = 0, white_pair = 0, b = 0, w = 0;
        int black_rest[3] = {0,0,0};
        int white_rest[3] = {0,0,0};
        for(int i = 0; i < 5; i++){
            if(black_count[i] == 2)
                black_pair = black_int[i];
            if(white_count[i] == 2)
                white_pair = white_int[i];
        }

        for(int i = 0; i < 5; i++){
            if(black_int[i] != black_pair){
                black_rest[b] = black_int[i];
                b++;
            }
            if(white_int[i] != white_pair){
                white_rest[w] = white_int[i];
                w++;
            }
        }

        if(black_pair > white_pair)
            cout << "Black wins." << endl;
        else if(white_pair > black_pair)
            cout << "White wins." << endl;
        else{
            sort(black_rest, black_rest + 3);
            sort(white_rest, white_rest + 3);
            for(int i = 2; i >= 0; i--){
                if(black_rest[i] > white_rest[i]){
                    cout << "Black wins." << endl;
                    return;
                }
                else if(white_rest[i] > black_rest[i]){
                    cout << "White wins." << endl;
                    return;
                }
            }
            cout << "Tie." << endl;
            return;
        }
    }   
    else
        ;
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
            check_tie(black_num, white_num, black_weight);
    }
    return 0;
}