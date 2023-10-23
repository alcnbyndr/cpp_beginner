#include <string>
#include <iostream>

class Gun {
    public:
        std::string name;
        int bulletCapacity;
};

class Ak47 : public Gun {
    public:
        bool rapidSingle;
        int strapLength;
        bool binoculars;

        void fire(){
            std::cout << "Shot by AK47!\n";
        }
};

class Pistol : public Gun {
    public:
        int crownDesign;

        void fire(){
            std::cout << "Shot by Pistol!\n";
        }
};

class M1 : public Gun {
    public:
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
    gun_M1.name = "M1 new design\n";

// Even though we didn't specify the names of these guns in the classes itself
// It is inherited from the class Gun.
// We can see that it is possible to reach name of each objects.

    Ak47 gun_AK47;
    gun_AK47.fire();
    gun_AK47.name = "Ak47 new design\n";

    std::cout << gun_AK47.name;
    std::cout << gun_M1.name;
}