#include <string>
#include <iostream>

class Ak47{
    public:
        std::string name;
        int bulletCapacity;
        bool rapidSingle;
        int strapLength;
        bool binoculars;

        void fire(){
            std::cout << "Shot by AK47!\n";
        }
};


class Pistol{
    public:
        std::string name;
        int bulletCapacity;
        int crownDesign;

        void fire(){
            std::cout << "Shot by Pistol!\n";
        }
};

class M1{
    public:
        std::string name;
        int bulletCapacity;
        bool rapidSingle;
        int strapLength;
        int crownPosition;

        void fire(){
            std::cout << "Shot by M1!\n";
        }
};

int main(){
    M1 gun_M1;
    gun_M1.fire();

    Ak47 gun_AK47;
    gun_AK47.fire();
}