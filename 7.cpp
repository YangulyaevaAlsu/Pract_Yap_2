#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <ctime>

using namespace std;
struct Card {
    string mast;
    string nom;
    Card() {};
    Card(string a, string b ):mast(a),nom(b) {}
};
void zapol_deck(Card *deck_of_cards,string *just_mast,string *just_nom, bool *deck_empty)
{
    int index_deck = 0;
    for (int y=0; y<4; y++) {
        for (int x=0; x<9; x++) {
            deck_of_cards[index_deck] = Card(just_mast[y], just_nom[x]);
            index_deck++;
        }
    }
    *deck_empty = false;

}
void print_deck(Card* deck_of_cards, bool deck_empty)
{

    if (deck_empty == true) {
        cout<<"Колода пуста"<<endl;
    } else {
        cout<<"Колода 36 карт"<<endl;
        for (int i=0; i<36; i++) {
            cout<<i+1<<") "<<deck_of_cards[i].mast+deck_of_cards[i].nom<<endl;
        }
        cout<<" "<<endl;
    }
}
void find_dama(Card* deck_of_cards)
{
    bool dama = false;
    for (int i=0; i<36; i++) {
        if ((deck_of_cards[i].mast == "Пиковая") && (deck_of_cards[i].nom == "Дама")) {
            cout<<"Она находится на "<< i + 1<<" позиции."<<endl;
            dama = true;
        }
    }
    if (!dama) cout<<"Пиковой дамы тут нет."<<endl;
}
void find_tus(Card* deck_of_cards)
{

    bool tus = false;
    for (int i=0; i<36; i++) {
        if (deck_of_cards[i].nom == "T") {
            cout<<"Нашёлся туз:"<<deck_of_cards[i].mast+deck_of_cards[i].nom<<". На "<< i + 1 <<" позиции."<<endl;
            tus = true;
        }
    }
    if (!tus) cout<<"Тузов в колоде не наблюдается."<<endl;
}
void shuffle_deck(Card* deck_of_cards, bool *deck_empty)
{
    srand(time(0));
    random_shuffle(deck_of_cards, deck_of_cards+36);
}

void find_mast(Card* deck_of_cards)
{
    cout<<"Рядом стоящие карты с одинаковой мастью:"<<endl;
    for (int i=0; i<35; i++) {
        if (deck_of_cards[i].mast == deck_of_cards[i+1].mast) {
            cout<<deck_of_cards[i].mast+deck_of_cards[i].nom<< " : "<<deck_of_cards[i+1].mast+deck_of_cards[i+1].nom<<endl;
        }
    }
    cout<<" "<<endl;
}
void find_nom(Card* deck_of_cards)
{
    cout<<"Рядом стоящие карты с одинаковым номиналом:"<<endl;
    for (int i=0; i<35; i++) {
        if (deck_of_cards[i].nom == deck_of_cards[i+1].nom) {
            cout<<deck_of_cards[i].mast+deck_of_cards[i].nom<< " : "<<deck_of_cards[i+1].mast+deck_of_cards[i+1].nom<<endl;
        }
    }
    cout<<" "<<endl;
}

int main(int argc, char **argv)
{
    string just_mast[4] = {"Буби ","Черви ","Пики ","Крести "};
    string just_nom[9] = {"Tуз ","Kороль ","Королева ","Валет ","10 ","9 ","8 ","7 ","6 "};
    bool deck_empty = true;
    Card deck_of_cards[36] = {};
    unsigned n;
    do {
        cout<<"1 - Заполнение\t2 - Перемешивание колоды\t3 - Вывести все карты,\n4 - Поиск по масти\t5 - Поиск по номиналу\n6 - Поиск всех тузов\t7 Поиск дамы пик\t8 - Выход"<<endl;
        cin>>n;
        if (n == 1) {
            zapol_deck(deck_of_cards, just_mast, just_nom, &deck_empty);
        }
        if (n == 2) {
            shuffle_deck(deck_of_cards,&deck_empty );
        }
        if (n == 3) {
            print_deck(deck_of_cards, deck_empty);
        }
        if (n == 4) {
            find_mast(deck_of_cards);
        }
        if (n == 5) {
            find_nom(deck_of_cards);
        }
        if (n == 6) {
            find_tus(deck_of_cards);
        }
        if (n == 7) {
            find_dama(deck_of_cards);
        } 
    }while (n!=8);
    return 0;
}
