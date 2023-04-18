
#ifndef Card_h
#define Card_h
class Card {
public:
    Card(int num);
    int getNum(){
        return this->number;
    }
private:
    int number;
};
Card :: Card (int num) {
    this->number = num;
}

#endif