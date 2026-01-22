#include <string>
#include <iostream>

class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickName;
        std::string phoneNumber;
        std::string darkestSecret;
    
    public:
        std::string getFirstName() {return firstName;}
        std::string getLasttName() {return lastName;}
        std::string getNickName() {return nickName;}
        std::string getPhoneNumber() {return phoneNumber;}
        std::string getDarkestSecret() {return darkestSecret;}

        void setFirstName(std::string str) {firstName = str;}
        void setLastName(std::string str) {lastName = str;}
        void setNickName(std::string str) {nickName = str;}
        void setPhoneNumber(std::string str) {phoneNumber = str;}
        void setDarkestSecret(std::string str) {darkestSecret = str;}
};
