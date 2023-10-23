#include  <iostream>

class Calculate{
	public:
		int width;
		int height;
		int area;

		void input(){
			std::cout << "Please enter the height: " << std::endl;
			std::cin >> height;

			std::cout << "Please enter the width: " << std::endl;
			std::cin >> width;
		}

		void calculate(){
			area = height * width;
			std::cout << area << std::endl;
		}
};


int main()
{
	Calculate calculator;
	calculator.input();
	calculator.calculate();
}
