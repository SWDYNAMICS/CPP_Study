#include <iostream>
#include <cstring>
using namespace std;
class MyFreindInfo{
private:
    char *name;
    int age;
public:
    MyFreindInfo(char *name, int myage):age(myage){
        this -> name = new char[strlen(name) + 1];
        strcpy(this->name , name);
    }
    
    void ShowMyFriendInfo() const{
        cout << "name is " << name << endl;
        cout << "age is " << age << endl;
    }
    ~MyFreindInfo(){
        delete [] name;
    }
};
class MyFreindDetailInfo : public MyFreindInfo{
private:
    char *addr;
    char *phone;
public:
    MyFreindDetailInfo(char *name, int myage, char *addr, char *phone)
        :MyFreindInfo(name, myage)
    {
        this -> addr = new char[strlen(addr) + 1];
        strcpy(this->addr,addr);
        this -> phone = new char[strlen(phone) + 1];
        strcpy(this->phone,phone);
    }
    void ShowMyFreindDetailInfo() const {
        ShowMyFriendInfo();
        cout << "addr is " << addr << endl;
        cout << "phone number is " << phone << endl << endl;
    }
    ~MyFreindDetailInfo(){
        delete [] addr;
        delete [] phone;
    }
};
int main(){
    MyFreindDetailInfo guy1("Lee",18, "Seoul", "010-1234-1234");
    MyFreindDetailInfo guy2("Prk",48, "Incheon", "010-1444-1234");
    guy1.ShowMyFreindDetailInfo();
    guy2.ShowMyFreindDetailInfo();

    return 0;
}