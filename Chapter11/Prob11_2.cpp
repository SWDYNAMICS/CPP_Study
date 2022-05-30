#include <iostream>
#include <cstring>
using namespace std;
class Book{
private:
    char *title;
    char *isbn;
    int price;
public:
    Book(char *title, char *isbn, int bookPrice) : price(bookPrice){
        this -> title = new char[strlen(title) + 1];
        strcpy(this->title, title);
        this -> isbn = new char[strlen(isbn) + 1];
        strcpy(this->isbn, isbn);
    }
    void BookInfo(){
        cout << "title : " << title << endl;
        cout << "isbn : " << isbn << endl;
        cout << "price : " << price << endl;
    }
    Book& operator=(const Book& ref){
        delete []title;
        delete []isbn;

        title = new char[strlen(ref.title) + 1];
        strcpy(title, ref.title);
        isbn = new char[strlen(ref.isbn) + 1];
        strcpy(isbn, ref.isbn);
        price = ref.price;
        return *this;
    }
    ~Book(){
        delete [] title;
        delete [] isbn;
    }
};
class Ebook : public Book{
private:
    char *DRMkey;
public:
    Ebook(char *title, char *isbn, int bookPrice, char * DRMkey): Book(title, isbn, bookPrice) {
        this->DRMkey = new char[strlen(DRMkey) + 1];
        strcpy(this->DRMkey, DRMkey);
    }
    Ebook& operator=(const Ebook& ref){
        Book::operator=(ref);
        delete [] DRMkey;
        DRMkey = new char[strlen(ref.DRMkey) + 1];
        strcpy(DRMkey, ref.DRMkey);
        return *this;
    }
    void EBookInfo(){
        BookInfo();
        cout << "key : " << DRMkey << endl;
    }
    ~Ebook(){
        delete [] DRMkey;
    }
};
int main(){
    Ebook ebook1("How to get a job", "123-123-123", 120000, "asdf111");
    Ebook ebook2 = ebook1;
    ebook2.EBookInfo();
    Ebook ebook3("dummy","dummy",0,"dummy");
    ebook3.EBookInfo();
    ebook3 = ebook2;
    ebook3.EBookInfo();
    return 0;
}