// Użyj odpowiedniego algorytmu STL, aby sprawdzić, czy wszystkie elementy wektora numbers są podzielne przez 3.

// std::vector numbers = {18, 21, 36, 90, 27, 14, 103};
// Zaimplementuj 3 wersje:

// lambda
// funktor
// funkcja

#include <iostream>
#include <algorithm>
#include <vector>

class checkNum{
    public:
        bool operator() (int num){
            return num % 3 == 0;
        }

};

bool checkNumFunction(int num){
    return num % 3 == 0;
}

int main(){
    std::vector numbers = {18, 21, 36, 90, 27, 14, 103};
    bool flag = true;

    auto search_number = std::find_if(numbers.begin(), numbers.end(), [](auto num){return num %3 != 0;});
    std::cout<<*search_number<<std::endl;

    std::cout<<"Lambda\n";

    auto check = [](auto num){return num % 3 == 0;};

    flag = std::all_of(numbers.begin(), numbers.end(), check);
    if(flag)
        std::cout<<"Liczby sa podzielne przez 3 w wektorze\n";
    else
        std::cout<<"Liczby NIE sa podzielne przez 3 w wektorze\n";

    std::cout<<"Funktor\n";
    flag = true;

    flag = std::all_of(numbers.begin(), numbers.end(), checkNum{});
    if(flag)
        std::cout<<"Liczby sa podzielne przez 3 w wektorze\n";
    else
        std::cout<<"Liczby NIE sa podzielne przez 3 w wektorze\n";

    std::cout<<"Funkcja\n";
    flag = true;
    auto *ptrFun = &checkNumFunction;

        flag = std::all_of(numbers.begin(), numbers.end(), ptrFun);
    if(flag)
        std::cout<<"Liczby sa podzielne przez 3 w wektorze\n";
    else
        std::cout<<"Liczby NIE sa podzielne przez 3 w wektorze\n";



    return 0;
}