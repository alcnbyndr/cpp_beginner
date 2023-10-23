#include <string>
#include <iostream>

class Message{
	public:
		std::string text;
		void write_msg() {
			std::cout << text << std::endl;
		}
};


int main()
{
	Message msg_en;
	msg_en.text = "Hello!";
	msg_en.write_msg();

	Message msg_es;
	msg_es.text = "Hola!";
	msg_es.write_msg();

	Message msg_tr;
	msg_tr.text = "Merhaba!";
	msg_tr.write_msg();
}
